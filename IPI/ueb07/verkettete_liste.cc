#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>
typedef int ListElementType;

struct ListElement {
    ListElement* next;
    ListElementType value;
};

struct LinkedList {
    ListElement* first;
};

// forward declaration
void list_printer(const LinkedList* list);

// leere Liste erzeugen
void empty_list(LinkedList* list) { list->first = 0; }

// Element in Liste suchen und ausgeben, sofern gefunden
ListElement* find_element(const LinkedList& list,
                          ListElementType targetElement) {
    for (ListElement* p = list.first; p != 0; p = p->next) {
        if (p->value == targetElement) return p;
    }

    return 0;
}

// Element in Liste einfuegen
void insert_element(LinkedList* list, ListElement* where,
                    ListElement* element) {
    if (where == 0) {
        element->next = list->first;
        list->first = element;
    } else {
        element->next = where->next;
        where->next = element;
    }
}

// Element aus Liste entfernen und ausgeben
ListElement* pop_element(LinkedList* list, ListElement* where) {
    ListElement* element;

    if (where == 0) {
        element = list->first;

        if (element != 0) {
            list->first = element->next;
        }

        return element;
    }

    element = where->next;

    if (element != 0) {
        where->next = element->next;
    }

    return element;
}

LinkedList create_circular_list(int length, int offset) {
    LinkedList list = LinkedList();
    ListElement* lastElement = 0;

    for (int i = offset; i < offset + length; ++i) {
        ListElement* newElement = new ListElement();
        newElement->value = i;

        insert_element(&list, lastElement, newElement);

        lastElement = newElement;

        // Letztes Element zeigt auf Startelement
        if (i == offset + length - 1) {
            newElement->next = list.first;
        }
    }

    return list;
}

LinkedList create_linear_list(int length, ListElement* circularListElement) {
    LinkedList list = LinkedList();
    ListElement* lastElement = 0;

    for (int i = 0; i < length; ++i) {
        ListElement* newElement = new ListElement();
        newElement->value = i;

        insert_element(&list, lastElement, newElement);

        lastElement = newElement;

        // Letztes Element zeigt auf Element der zyklischen Liste
        if (i == length - 1) {
            lastElement->next = circularListElement;
        }
    }

    return list;
}

// Liste anhand von n und k erzeugen
LinkedList create_n_k_list(int circularLength, int linearLength) {
    if (circularLength <= 0 && linearLength <= 0) {
        return LinkedList();
    }

    ListElement* jointElement = 0;

    LinkedList circularList;
    LinkedList linearList;

    if (circularLength != 0) {
        circularList = create_circular_list(circularLength, linearLength);
        jointElement = circularList.first;
    }

    if (linearLength != 0) {
        linearList = create_linear_list(linearLength, jointElement);
        return linearList;
    } else {
        return circularList;
    }
}

// n mit Hase und Igel berechnen
int hase_igel_algo(LinkedList* list) {
    if (list->first == 0) {
        return 0;
    }

    int counter = 0;
    bool counterFlag = false;
    ListElement* startAdresse;

    ListElement* haseAdresse = list->first;
    ListElement* igelAdresse = list->first;

    while (true) {
        if (igelAdresse->next) {
            igelAdresse = igelAdresse->next;
        } else {
            break;
        }

        if (haseAdresse->next && haseAdresse->next->next) {
            haseAdresse = haseAdresse->next->next;
        }

        if (counterFlag) {
            counter++;

            if (startAdresse == igelAdresse) {
                break;
            }
        }

        if (igelAdresse == haseAdresse) {
            startAdresse = igelAdresse;
            counterFlag = true;
        }
    }

    return counter;
}

// Diese Funktion hat lediglich dem Testen gedient und kann daher ignoriert
// werden
void list_printer(const LinkedList* list) {
    if (list->first == 0) {
        std::cout << "Leer";
    }

    ListElement* element = list->first;

    while (true) {
        std::cout << element->value << "-";

        if (!element->next) {
            break;
        }

        element = element->next;

        std::getchar();
    }
}

int main() {
    //Normalfall
    LinkedList normalfall = create_n_k_list(5, 5);
    int nNormalfall = hase_igel_algo(&normalfall);
    std::cout << "Normalfall: " << nNormalfall << std::endl;

    // reiner Zyklus
    LinkedList reinerZyklus = create_n_k_list(5, 0);
    int nReinerZyklus = hase_igel_algo(&reinerZyklus);
    std::cout << "Reiner Zyklus: " << nReinerZyklus << std::endl;

    // lineare Liste
    LinkedList lineareListe = create_n_k_list(0, 5);
    int nLineareListe = hase_igel_algo(&lineareListe);
    std::cout << "Lineare Liste: " << nLineareListe << std::endl;

    // leere Liste
    LinkedList leereListe = create_n_k_list(0, 0);
    int nLeereListe = hase_igel_algo(&leereListe);
    std::cout << "Leere Liste: " << nLeereListe << std::endl;
}
