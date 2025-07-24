% Declare discontiguous predicates
:- discontiguous days_between/3.
:- discontiguous print_study_plan/2.
:- discontiguous print_subject_details/3.
:- discontiguous print_preference_message/1.
:- discontiguous print_deadline_info/3.
:- discontiguous print_exam_info/3.

%% ========== Dynamic Predicates ==========

:- dynamic study_time/3.
:- dynamic subject/1.
:- dynamic enjoys/1.
:- dynamic dislikes/1.
:- dynamic exam_date/2.
:- dynamic deadline/2.

%% ========== Day Sequence Management ==========

% Define the canonical day sequence
day_sequence([monday, tuesday, wednesday, thursday, friday, saturday, sunday]).

% Predicate to validate day order
valid_day_order(Day1, Day2) :-
    day_sequence(Sequence),
    nth1(Index1, Sequence, Day1),
    nth1(Index2, Sequence, Day2),
    Index1 =< Index2.

%% ========== Input Collection ==========

% Initialize study planner with user inputs
initialize_planner :-
    % Clear existing data
    retractall(study_time(_, _, _)),
    retractall(subject(_)),
    retractall(enjoys(_)),
    retractall(dislikes(_)),
    retractall(exam_date(_, _)),
    retractall(deadline(_, _)),
    
    % Collect inputs with validation
    collect_subjects,
    collect_study_hours,
    validate_study_times,
    collect_preferences,
    collect_exam_dates,
    collect_deadlines.

% Collect subject information
collect_subjects :-
    write('Enter number of subjects: '),
    read(NumSubjects),
    collect_subjects(NumSubjects).

collect_subjects(0).
collect_subjects(N) :-
    N > 0,
    write('Enter subject name: '),
    read(Subject),
    assertz(subject(Subject)),
    N1 is N - 1,
    collect_subjects(N1).

% Collect daily study hours using day sequence
collect_study_hours :-
    get_current_date(CurrentDate),
    day_sequence(Days),
    collect_daily_hours(Days, CurrentDate).

% Modified collect_daily_hours to avoid singleton variables
collect_daily_hours([], _).
collect_daily_hours([Day|Rest], Date) :-
    format('Enter available study hours for ~w (0 for no study): ', [Day]),
    read(NumHours),
    (NumHours > 0 -> 
        assertz(study_time(Date, Day, NumHours))
    ; true),
    collect_daily_hours(Rest, Date).

% Validation predicate for study times
validate_study_times :-
    findall(Day-StudyHours, study_time(_, Day, StudyHours), StudyTimes),
    day_sequence(ValidDays),
    forall(member(Day-_, StudyTimes), 
           (member(Day, ValidDays) -> true 
            ; format('Warning: Invalid day ~w in study times~n', [Day]))).

% Collect subject preferences
collect_preferences :-
    write('Let\'s set your subject preferences.\n'),
    forall(subject(Subject), collect_subject_preference(Subject)).

collect_subject_preference(Subject) :-
    format('Do you enjoy ~w? (yes/no/neutral): ', [Subject]),
    read(Response),
    handle_preference(Response, Subject).

handle_preference(yes, Subject) :- assertz(enjoys(Subject)).
handle_preference(no, Subject) :- assertz(dislikes(Subject)).
handle_preference(neutral, _).

% Collect exam dates
collect_exam_dates :-
    write('Now, let\'s set exam dates.\n'),
    forall(subject(Subject), collect_exam_date(Subject)).

collect_exam_date(Subject) :-
    format('Enter exam date for ~w:\n', [Subject]),
    get_date_input(ExamDate),
    assertz(exam_date(Subject, ExamDate)).

% Collect assignment deadlines
collect_deadlines :-
    write('Finally, let\'s set assignment deadlines.\n'),
    forall(subject(Subject), collect_deadline(Subject)).

collect_deadline(Subject) :-
    format('Enter assignment deadline for ~w:\n', [Subject]),
    get_date_input(DeadlineDate),
    assertz(deadline(Subject, DeadlineDate)).

% Helper predicate to get date input
get_date_input(date(Year, Month, Day)) :-
    write('Year: '), read(Year),
    write('Month (1-12): '), read(Month),
    write('Day (1-31): '), read(Day).

% Get current date
get_current_date(date(Year, Month, Day)) :-
    write('Enter current date:\n'),
    get_date_input(date(Year, Month, Day)).

%% ========== Priority Management ==========

days_until_exam(Subject, CurrentDate, Days) :-
    exam_date(Subject, ExamDate),
    days_between(CurrentDate, ExamDate, Days).

get_subject_priorities(Date, PriorityList) :-
    findall(Days-Subject, (
        subject(Subject),
        days_until_exam(Subject, Date, Days)
    ), SubjectDays),
    sort(SubjectDays, SortedSubjects),
    assign_priority_levels(SortedSubjects, PriorityList).

assign_priority_levels([], []).
assign_priority_levels([_-Subject|Rest], [high-Subject|PriorityRest]) :-
    assign_remaining_priorities(Rest, PriorityRest).

assign_remaining_priorities([], []).
assign_remaining_priorities([_-Subject|Rest], [medium-Subject|[low-LastSubject]]) :-
    Rest = [_-LastSubject|_].

get_subject_priority(Subject, Date, Priority) :-
    get_subject_priorities(Date, PriorityList),
    member(Priority-Subject, PriorityList).

%% ========== Hour Allocation ==========

priority_allocation(high, 0.5).
priority_allocation(medium, 0.3).
priority_allocation(low, 0.2).

preference_multiplier(Subject, 1.2) :- enjoys(Subject), !.
preference_multiplier(Subject, 0.8) :- dislikes(Subject), !.
preference_multiplier(_, 1.0).

% Calculate study hours for all subjects
calculate_daily_hours(Date, TotalHours, StudyPlan) :-
    get_subject_priorities(Date, PriorityList),
    findall(Subject-StudyHours, (
        member(Priority-Subject, PriorityList),
        priority_allocation(Priority, BasePercentage),
        preference_multiplier(Subject, Multiplier),
        RawHours is TotalHours * BasePercentage * Multiplier,
        StudyHours is round(RawHours * 2) / 2
    ), InitialHours),
    adjust_hours_to_total(InitialHours, TotalHours, StudyPlan).

% Adjust hours to match daily total
adjust_hours_to_total(InitialHours, TargetTotal, AdjustedHours) :-
    findall(CurrentHours, member(_-CurrentHours, InitialHours), HoursList),
    sum_list(HoursList, CurrentTotal),
    AdjustmentFactor is TargetTotal / CurrentTotal,
    maplist(adjust_subject_hours(AdjustmentFactor), InitialHours, AdjustedHours).

adjust_subject_hours(Factor, Subject-CurrentHours, Subject-Adjusted) :-
    Adjusted is round(CurrentHours * Factor * 2) / 2.

%% ========== Output Formatting ==========

% Plan week with total hours summary
plan_week :-
    format('Weekly Study Plan~n'),
    format('=================~n~n'),
    day_sequence(WeekDays),
    (study_time(Date, _, _) ->
        calculate_weekly_hours(Date, TotalWeeklyHours),
        format('Total weekly study hours: ~2f~n~n', [TotalWeeklyHours]),
        print_week_schedule(WeekDays, Date)
    ;   
        format('No study times scheduled~n')
    ).

% Print full week schedule using day sequence
print_week_schedule([], _).
print_week_schedule([Day|Rest], Date) :-
    print_day_schedule(Day, Date),
    format('~n'),
    print_week_schedule(Rest, Date).

% Print single day schedule
print_day_schedule(Day, Date) :-
    (study_time(Date, Day, _) ->  % Changed Hours to _ here since we don't use the value
        plan_day(Date, Day)
    ;   
        capitalize_day(Day, CapDay),
        format('~w: No study hours scheduled~n', [CapDay])
    ).

% Plan single day with validation
plan_day(Date, Day) :-
    study_time(Date, Day, TotalHours),
    day_sequence(Days),
    member(Day, Days),
    format_date_header(Date, Day, TotalHours),
    calculate_daily_hours(Date, TotalHours, StudyPlan),
    print_study_plan(StudyPlan, Date).

% Format date header
format_date_header(date(Year, Month, Day), DayName, Hours) :-
    capitalize_day(DayName, CapDay),
    format('~w (~d-~2d-~2d)~n', [CapDay, Year, Month, Day]),
    format('Study Hours: ~w~n', [Hours]),
    format('----------------~n').

% Print complete study plan
print_study_plan([], _).
print_study_plan([Subject-Hours|Rest], Date) :-
    print_subject_details(Subject, Hours, Date),
    (Rest \= [] -> format('~n') ; true),
    print_study_plan(Rest, Date).

% Print details for one subject
print_subject_details(Subject, Hours, Date) :-
    format('  Spend ~1f hours studying ~w~n', [Hours, Subject]),
    print_preference_message(Subject),
    print_deadline_info(Subject, Date),
    print_exam_info(Subject, Date).

% Print subject preference message
print_preference_message(Subject) :-
    (enjoys(Subject) ->
        format('    You enjoy this subject, so study it diligently!~n')
    ; dislikes(Subject) ->
        format('    Remember, you don\'t enjoy this subject, so stay motivated.~n')
    ; true).

% Print deadline information
print_deadline_info(Subject, CurrentDate) :-
    (deadline(Subject, date(Year, Month, Day)) ->
        days_between(CurrentDate, date(Year, Month, Day), DaysLeft),
        format('    Assignment deadline: ~d-~2d-~2d (~w days remaining)~n',
               [Year, Month, Day, DaysLeft])
    ; true).

% Print exam information
print_exam_info(Subject, CurrentDate) :-
    exam_date(Subject, date(Year, Month, Day)),
    days_between(CurrentDate, date(Year, Month, Day), DaysLeft),
    get_subject_priority(Subject, CurrentDate, Priority),
    format('    Exam date: ~d-~2d-~2d (~w days remaining - ~w priority)~n',
           [Year, Month, Day, DaysLeft, Priority]).

%% ========== Utility Predicates ==========

% Calculate days between two dates
days_between(date(Y1,M1,D1), date(Y2,M2,D2), Days) :-
    date_time_stamp(date(Y1,M1,D1,0,0,0,0,'UTC',-), Stamp1),
    date_time_stamp(date(Y2,M2,D2,0,0,0,0,'UTC',-), Stamp2),
    Days is floor((Stamp2 - Stamp1) / 86400).

% Helper predicate to capitalize day name
capitalize_day(Day, CapDay) :-
    atom_chars(Day, [First|Rest]),
    upcase_atom(First, UpperFirst),
    atom_chars(CapDay, [UpperFirst|Rest]).

% Get next day in sequence
next_day(CurrentDay, NextDay) :-
    day_sequence(Days),
    nth1(Index, Days, CurrentDay),
    NextIndex is (Index mod 7) + 1,
    nth1(NextIndex, Days, NextDay).

% Get previous day in sequence
previous_day(CurrentDay, PrevDay) :-
    day_sequence(Days),
    nth1(Index, Days, CurrentDay),
    PrevIndex is ((Index - 2) mod 7) + 1,
    nth1(PrevIndex, Days, PrevDay).

% Calculate total weekly hours
calculate_weekly_hours(Date, TotalHours) :-
    findall(Hours, study_time(Date, _, Hours), HoursList),
    sum_list(HoursList, TotalHours).

%% ========== Main Program ==========

% Main entry point
start_planner :-
    write('Welcome to the Study Schedule Planner!\n'),
    initialize_planner,
    plan_week.