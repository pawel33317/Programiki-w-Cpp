class Memento {
    private:
    int mVar1;

    private:
        Memento(){}
        Memento(const Memento& source){ mVar1 = source.mVar1;}
        Memento &operator=(const Memento &source)
            {mVar1 = source.mVar1; return *this;}

        void setVar1(int var) {mVar1 = var;}
        int getVar1() const {return mVar1;}

        friend class Orginator;
};


class Orginator {
private:
    int mVar1;
    int mVar2;
public:
    void setVar1(int var) {mVar1 = var;}
    int getVar1() const {return mVar1;}
    void setVar2(int var) {mVar2 = var;}
    int getVar2() const {return mVar2;}

    Memento* saveState(){
        Memento* memento = new Memento;
        memento->setVar1(getVar1());
        return memento;
    }

    void restoreState(Memento* memento){
        setVar1(memento->getVar1());
    }
};

int main()
{
    Orginator* originator = new Orginator;
    originator->setVar1(10);
    originator->setVar1(11);

    Memento* memento = originator->saveState();


    originator->setVar1(12);

    originator->restoreState(memento);
}
