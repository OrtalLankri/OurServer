
#ifndef OURSERVER_STATE_H
#define OURSERVER_STATE_H

template <class T> class State {
public:
    virtual T getState() = 0;
    virtual double getCost() = 0;
    virtual void setCost(double cost) = 0;
    virtual double getTempCost() = 0;
    virtual void setTempCost(double cost) = 0;
    virtual State<T>* getCameFrom() = 0;
    virtual void setCameFrom(State<T>* state) = 0;
    virtual bool equals(State<T>* s) = 0;
};

#endif //OURSERVER_STATE_H
