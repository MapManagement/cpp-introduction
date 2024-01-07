template <typename F, typename S, typename T> class Triplet {
  F FirstItem;
  S SecondItem;
  T ThirdItem;

public:
  Triplet(F firstItem, S secondItem, T thirdItem) {
    FirstItem = firstItem;
    SecondItem = secondItem;
    ThirdItem = thirdItem;
  }

    // Setter-Methoden
    void setFirst(F item) {
        FirstItem = item;
    }

    void setSecond(S item) {
        SecondItem = item;
    }

    void setThird(T item) {
        ThirdItem = item;
    }

    // Getter-Methoden
    F first() {
        return FirstItem;
    }

    S second() {
        return SecondItem;
    }

    T third() {
        return ThirdItem;
    }
};
