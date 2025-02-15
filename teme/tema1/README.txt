Problema #1 - Jocuri de societate
Pentru prima problema vom citi initial HP-ul, numarul de elemente (N), urmand de N-ori tipul elementului si valoarea acestuia. Daca elementul este de tip HEAL, valoarea acestuia o vom aduna la HP-ul eroului, iar daca elementul este de tip SHIELD, il vomm retine intr-un vector pe care il vom folosi mai tarziu; in cazul in care elementul nu este niciunul de mai sus, vom afisa un mesaj de erorare. 
Elementele vectorului cu scuturi, le vom sorta ca sa putem sa gasim eficient ( cu cautare binara) scutul potrivit pentru lupta noastra.
La urmatorul pas citim numarul de batalii (M) si de M ori o valoare care reprezinta boss fightul. 
Simularea ueni batalii este compusa din mai multi pasi:
1. cautam shield-ul adecvat pentru valoarea citita. El reprezinta cea mai mare valoare mai mica decat boss_fightul, sau cel mai muc scut, daca aceste este mai mare decat boss_fightul. Dupa ce am gasit acesta valoare o vom sterge din vectorul nostru
2. calculam damage-ul produs de batalie, respctiv diferenta dintre boss_fight si scut daca valoarea primului este mai mare sau 0, in caz contrar
3. scadem din hp damage-ul
Dupa batalie trebuie sa afisam rezultatul acesteia, respectiv HP-ul personajului si (eventualul) shield pe care l-a folosit
Vom repeta procesul pana la finalizarea raufacatorilor, afisand un mesaj pozitiv, sau pana cand HP-ul personalui este mai mic sau egal cu 0.

Problema #2 - Forme
Acesta problema ne-a permis scrierea unui cod modularizat si bine structurat, citind initial numarul de cerinte si fiecare cerinta in parte.
Ele au fost diferentiale printr-o varibila char, care sa ne determine unul din cele 5 (6- cel in care nu e niciunul din cele 5) cazuri.
Pentru fiecare cerinta am citit datele care sa o caracterizeze si am realizat cazurile limita, in care ea nu poate fi dusa la final: latura este mai mica sau egala cu 0 (sau para pentru cruce si fereastra), sau unghiul nu este divizibul cu 90 (triunghi, cruce ), respcectiv 45 (patrat).
Pentru cazul in care figura este patrat, daca unghiul este divizibil cu 90, vom afisa un patrat normal, iar in cazul de 45, vom afisa un romb, ce reprezinta interiorul patratului de latura 2 * l - 1.
Pentru dreptunghim nu avem niciun caz special, doar un dreptunghiu normal de l1 si l2;
Pentru cruce avem 2 posibilitati: daca unghiul redus* este divizibil cu 90, ramane o cruce, ce reprezinta coloana, respectiv linia de pe o matrice patratica de dimeniune l;
				  altfel, crucea se transforma in diagonalele unui patrat de dimensiune l
Pentru triunghi avem 4 cazuri, daca unghiul redus* este 0: el reprezinta celule de sub diagonalei principale
						       90: el reprezinta celule de deasupra diagonalei secundare
						      180: el reprezinta celule de deasupra diagonalei principale
						      270: el reprezinta celule de sub diagonalei secundare
Pentru fereastra avem o singura posibilitate, fereasta reprezinta un chenarul unui patrat combinat cu o cruce de aceasi dimensiune.
*pentru fiecare unghi, am calculat modulul la 360, care este perioda principala pentru rotire, si daca era negativ, am adunat 360 pentru a-l aduce in partea pozitiva.

Problema #3 - Simulator de circuite
Problema a III-a se imparte in doua probleme independente, in functie de ce teoreme doreste sa testeze.
Daca cerinta nu este I sau II, vom afisa un mesaj de eroare intrucat ea depaseste problema noastra.
Pentru prima teorema, am realizat un graf orientat care sa simuleze circuitul nostru, in care am stocat intensitatile. 
Am realizat functia nod1 care sa ne ajute in realizarea a doua task-uri: ne va returna prin variabila K, daca circuitul nostru este deschis in nodul pentru care o apelam (adica nu avem niciun curent care sa intre sau sa iasa), si ne returneaza suma intensitatile curentilor care intra si care ies.
Urmatorul pas a fost sa ne folosim de functia definita anterior ca sa verificam daca circuitul este deschis si sa afisam un mesaj de eroare in acest caz.
Dupa aceasta a trebuit sa verificam veridicitatea teoremei pe ciruittul dat, adica daca in fiecare nod, suma intrarilor este egala cu suma iesirilor, folosind functia de mai devreme.
Pentru a doua cerinta, vom citi pentru fiecare pereche de noduri, o lista cu elemente pe acel "fir". Daca elementul este rezistor, ii vom calcula tensiunea (V=I*R) si o vom aduna la 
tensiunea de iesire, respectiv daca este sursa o vom adauga la teniunea de intrare. (daca tensiunea unui generetor este < 0, vom afisa un mesaj de eroare).
La final vom verifica daca legea a doua se respecta (vin ~= vout ->diferenata accepatabila < 10^6), in acest caz vom afisa un mesaj de succes, altfel vom afisa un mesaj de eroare ce va include cele doua tensiuni. 

Problema #4 - Seven segment display
Acesta problema am impartit-o in mai multe subprobleme pentru a simplifica structura code-ului.
Prima data citim cerinta si avem mai multe cazuri: 
1. Q- se termina programul
2. P- afisam matricea
3. F- aici trebuie sa formam matricea. pentru acesta o vom initializa, dupa dimensiunile primite, inlocuind fiecare segment prezentat in cerinta cu litera corespunzatoare, respectiv. 0, daca celula nu face parte din niciun segment. Pentru acesta ne-am folosit de niste relatii in functie de dimensiunile matricei si lungimea si latimea segmentului. Dupa acesta vom inlocui valorile in functie de cifra primita, conform imaginei din cerinta (respectiv afisam un mesaj de eroare daca nu am citit o cifra.)
4. W/S/A/D- pentru acesta am realizat permutari circulare asupra matricei. de ex: daca vrem sa o translatam la stamga cu 1, prima coloana va deveni ultima si celelalte se vor translata cu o pozitie la stranga. 