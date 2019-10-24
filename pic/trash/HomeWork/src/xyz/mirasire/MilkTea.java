package xyz.mirasire;

public abstract class MilkTea {
    public String size;
    public TakeAPI takeapi;
    public MilkTea(TakeAPI takeapi) {
        this.takeapi = takeapi;
    }
}
