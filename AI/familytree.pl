% Define males and females
male(dudhram).
male(manohar).
male(khushal).
male(madan).
male(pramod).
male(vinod).
male(moreshwar).
male(eknath).
male(girdhar).
male(bhumesh).
male(ravi).
male(raju).
male(abhishek).
male(shreyash).
male(utkarsha).
male(bhavesh).
male(gaurav).
male(kartik).
male(atharva).
male(rudra).
male(kaustubh).
male(om).
male(sai).

female(malti).
female(geeta).
female(kalpana).
female(nalu).
female(ganga).
female(pushpa).
female(hina).
female(nisha).
female(dipali).
female(anita).
female(urmila).
female(shrutika).
female(vedika).
female(durva).

% Define marriage relationships
married(manohar, malti).
married(khushal, geeta).
married(madan, kalpana).
married(pramod, nalu).
married(vinod, ganga).
married(moreshwar, pushpa).
married(eknath, hina).
married(girdhar, nisha).
married(bhumesh, dipali).
married(ravi, anita).
married(raju, urmila).

% Define parent-child relationships
parent(dudhram, manohar).
parent(dudhram, khushal).
parent(dudhram, madan).

parent(manohar, pramod).
parent(manohar, vinod).
parent(manohar, moreshwar).
parent(malti, pramod).
parent(malti, vinod).
parent(malti, moreshwar).

parent(khushal, eknath).
parent(khushal, girdhar).
parent(khushal, bhumesh).
parent(geeta, eknath).
parent(geeta, girdhar).
parent(geeta, bhumesh).

parent(madan, ravi).
parent(madan, raju).
parent(kalpana, ravi).
parent(kalpana, raju).

parent(pramod, abhishek).
parent(pramod, shrutika).
parent(nalu, abhishek).
parent(nalu, shrutika).

parent(vinod, shreyash).
parent(vinod, utkarsha).
parent(ganga, shreyash).
parent(ganga, utkarsha).

parent(moreshwar, bhavesh).
parent(moreshwar, gaurav).
parent(pushpa, bhavesh).
parent(pushpa, gaurav).

parent(eknath, kartik).
parent(eknath, atharva).
parent(hina, kartik).
parent(hina, atharva).

parent(girdhar, rudra).
parent(girdhar, vedika).
parent(nisha, rudra).
parent(nisha, vedika).

parent(bhumesh, kaustubh).
parent(bhumesh, durva).
parent(dipali, kaustubh).
parent(dipali, durva).

parent(ravi, om).
parent(ravi, sai).
parent(anita, om).
parent(anita, sai).

parent(raju, vedika).
parent(urmila, vedika).

% Define basic family relationships
father(X, Y) :- male(X), parent(X, Y).
mother(X, Y) :- female(X), parent(X, Y).
child(X, Y) :- parent(Y, X).
son(X, Y) :- male(X), child(X, Y).
daughter(X, Y) :- female(X), child(X, Y).

% Sibling relationships
sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.
brother(X, Y) :- male(X), sibling(X, Y).
sister(X, Y) :- female(X), sibling(X, Y).

% Grandparent relationships
grandparent(X, Y) :- parent(X, Z), parent(Z, Y).
grandfather(X, Y) :- male(X), grandparent(X, Y).
grandmother(X, Y) :- female(X), grandparent(X, Y).
grandchild(X, Y) :- grandparent(Y, X).
grandson(X, Y) :- male(X), grandchild(X, Y).
granddaughter(X, Y) :- female(X), grandchild(X, Y).

% Marriage relationships
spouse(X, Y) :- married(X, Y); married(Y, X).
wife(X, Y) :- female(X), spouse(X, Y).
husband(X, Y) :- male(X), spouse(X, Y).

% Fixed in-law relationships
mother_in_law(X, Y) :- female(X), 
    (spouse(Y, Child), parent(X, Child);  % mother of Y's spouse
     spouse(Y, Z), parent(X, Z)).         % mother of Y's spouse's parent

father_in_law(X, Y) :- male(X),
    (spouse(Y, Child), parent(X, Child);  % father of Y's spouse
     spouse(Y, Z), parent(X, Z)).         % father of Y's spouse's parent

daughter_in_law(X, Y) :- female(X), spouse(X, Child), parent(Y, Child).
son_in_law(X, Y) :- male(X), spouse(X, Child), parent(Y, Child).

% Enhanced aunt/uncle relationships
uncle(X, Y) :- 
    (male(X), sibling(X, Parent), parent(Parent, Y));                % by blood
    (male(X), spouse(X, Sibling), sibling(Sibling, Parent), parent(Parent, Y)). % by marriage

aunt(X, Y) :- 
    (female(X), sibling(X, Parent), parent(Parent, Y));              % by blood
    (female(X), spouse(Sibling, X), sibling(Sibling, Parent), parent(Parent, Y)); % by marriage
    (female(X), spouse(X, Sibling), sibling(Sibling, Parent), parent(Parent, Y)). % spouse of uncle

% Updated Sister-in-law relationships
sister_in_law(X, Y) :- 
    female(X), (
        spouse(X, Person1), sibling(Person1, Y);          % wife of Y's sibling
        spouse(Y, Person2), sibling(Person2, X);          % sister of Y's spouse
        sibling(Person3, Y), spouse(Person3, X);          % married to Y's sibling
        spouse(Y, Person4), spouse(Sibling, X), sibling(Person4, Sibling) % wives of siblings
    ).

% Updated Brother-in-law relationships
brother_in_law(X, Y) :- 
    male(X), (
        spouse(X, Person1), sibling(Person1, Y);          % husband of Y's sibling
        spouse(Y, Person2), sibling(Person2, X);          % brother of Y's spouse
        sibling(Person3, Y), spouse(Person3, X);          % married to Y's sibling
        spouse(Y, Person4), spouse(Sibling, X), sibling(Person4, Sibling) % husbands of siblings
    ).

% Paternal/maternal relationships
paternal_uncle(X, Y) :- male(X), brother(X, Father), father(Father, Y).
maternal_uncle(X, Y) :- male(X), brother(X, Mother), mother(Mother, Y).
paternal_aunt(X, Y) :- female(X), sister(X, Father), father(Father, Y).
maternal_aunt(X, Y) :- female(X), sister(X, Mother), mother(Mother, Y).

% Nephew/Niece relationships
nephew(X, Y) :- male(X), (child(X, Parent), sibling(Parent, Y); child(X, Parent), spouse(Y, Sibling), sibling(Parent, Sibling)).
niece(X, Y) :- female(X), (child(X, Parent), sibling(Parent, Y); child(X, Parent), spouse(Y, Sibling), sibling(Parent, Sibling)).

% Cousin relationships
cousin(X, Y) :- parent(P1, X), parent(P2, Y), sibling(P1, P2).

% Great-grandparent relationships
great_grandparent(X, Y) :- parent(X, Z), grandparent(Z, Y).
great_grandchild(X, Y) :- grandparent(Y, Z), parent(Z, X).

% Updated find_relation predicate with proper ordering
find_relation(Person1, Person2, Relation) :- 
    ( spouse(Person1, Person2) -> Relation = 'spouse'
    ; parent(Person1, Person2) -> Relation = 'parent'
    ; child(Person1, Person2) -> Relation = 'child'
    ; sister_in_law(Person1, Person2) -> Relation = 'sister-in-law'
    ; brother_in_law(Person1, Person2) -> Relation = 'brother-in-law'
    ; mother_in_law(Person1, Person2) -> Relation = 'mother-in-law'
    ; father_in_law(Person1, Person2) -> Relation = 'father-in-law'
    ; daughter_in_law(Person1, Person2) -> Relation = 'daughter-in-law'
    ; son_in_law(Person1, Person2) -> Relation = 'son-in-law'
    ; grandparent(Person1, Person2) -> Relation = 'grandparent'
    ; grandchild(Person1, Person2) -> Relation = 'grandchild'
    ; great_grandparent(Person1, Person2) -> Relation = 'great-grandparent'
    ; great_grandchild(Person1, Person2) -> Relation = 'great-grandchild'
    ; cousin(Person1, Person2) -> Relation = 'cousin'
    ; sibling(Person1, Person2) -> Relation = 'sibling'
    ; brother(Person1, Person2) -> Relation = 'brother'
    ; sister(Person1, Person2) -> Relation = 'sister'
    ; aunt(Person1, Person2) -> Relation = 'aunt'
    ; uncle(Person1, Person2) -> Relation = 'uncle'
    ; paternal_uncle(Person1, Person2) -> Relation = 'paternal uncle'
    ; maternal_uncle(Person1, Person2) -> Relation = 'maternal uncle'
    ; paternal_aunt(Person1, Person2) -> Relation = 'paternal aunt'
    ; maternal_aunt(Person1, Person2) -> Relation = 'maternal aunt'
    ; nephew(Person1, Person2) -> Relation = 'nephew'
    ; niece(Person1, Person2) -> Relation = 'niece'
    ; Relation = 'no direct relation'
    ).

% Helper predicates to find all relatives of a specific type
find_children(Person, Children) :- 
    setof(Child, parent(Person, Child), Children).

find_parents(Person, Parents) :- 
    setof(Parent, parent(Parent, Person), Parents).

find_siblings(Person, Siblings) :- 
    setof(Sibling, sibling(Person, Sibling), Siblings).

find_grandparents(Person, Grandparents) :- 
    setof(GP, grandparent(GP, Person), Grandparents).

find_grandchildren(Person, Grandchildren) :- 
    setof(GC, grandchild(GC, Person), Grandchildren).

find_cousins(Person, Cousins) :- 
    setof(Cousin, cousin(Person, Cousin), Cousins).

find_uncles_aunts(Person, UnclesAunts) :- 
    setof(UA, (uncle(UA, Person); aunt(UA, Person)), UnclesAunts).

find_nephews_nieces(Person, NephewsNieces) :- 
    setof(NN, (nephew(NN, Person); niece(NN, Person)), NephewsNieces).

find_great_grandparents(Person, GreatGrandparents) :- 
    setof(GGP, great_grandparent(GGP, Person), GreatGrandparents).

find_great_grandchildren(Person, GreatGrandchildren) :- 
    setof(GGC, great_grandchild(GGC, Person), GreatGrandchildren).

% Initialization directive
:- initialization(main).

main :-
    % Example query: Find relation between two people
    find_relation(manohar, pramod, Relation),
    write('Relation between manohar and pramod: '), write(Relation), nl,
    halt.