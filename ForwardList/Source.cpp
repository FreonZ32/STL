#include<iostream>
#include<Windows.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Car
{
    class Engine;
    class FuelTank;
   // class FuelTankDisplay;

    class Engine
    {
        bool EngineIsRunning;
    public:
        bool get_EngineIsRunning()const
        {return EngineIsRunning;}
        void set_EngineIsRunning(bool EngineIsRunning)
        {this->EngineIsRunning = EngineIsRunning;}

        Engine(bool EngineIsRunning = false)
        {this->EngineIsRunning = EngineIsRunning; }
        ~Engine(){}

        void EngineStart() 
        {EngineIsRunning = true;}
        void EngineStop()
        {EngineIsRunning = false;}

        void Consume(FuelTank& FueTan)
        {
            double fillLevel = FueTan.get_Fill_Level();
            fillLevel -= 0.0003;
            FueTan.set_FillLevel(fillLevel,*this);
        }

       // void RunningIdle();
    };
    class FuelTank
    { 
        double FillLevel;
        bool IsOnReserve;
        bool IsComplete;
      

    public:
        double get_Fill_Level()const
        {return FillLevel;}
        void set_FillLevel(double FillLevel, Engine& Eng)
        {
            if (FillLevel <= double(5)) { this->IsOnReserve = true;}
            if (FillLevel <= 0) { Eng.EngineStop(); this->FillLevel = 0; this->IsComplete = true; return; }
            this->FillLevel = FillLevel;
        }
        FuelTank(double FillLevel = 20,bool IsOnReserve = false,bool IsComplete = false)
        {
            this->FillLevel = FillLevel;
            this->IsOnReserve = IsOnReserve;
            this->IsComplete = IsComplete;
        }
        ~FuelTank(){}

        void print()
        {
            cout << "Кол-во топлива: " << FillLevel << endl;
            if (IsComplete)cout << "Топливо кончилось" << endl;
            else if (IsOnReserve)cout << "Загорелся чек топлива" << endl;
        } 
        void Refuel(double liters);
        /*class FuelTankDisplay
        {
            double FillLevel;
            bool IsOnReserve;
            bool IsComplete;
        public:
            FuelTankDisplay(){}
            ~FuelTankDisplay(){}
        };*/
       // friend class Engine;
    };
    Engine Eng;
    FuelTank FueTan;
   // FuelTank::FuelTankDisplay FueTanDis;
public:
    Engine get_Eng()const
    {return Eng;}
    FuelTank get_FueTan()const
    {return FueTan;}
   /* FuelTank::FuelTankDisplay get_FueTanDis()
    {return FueTanDis;}*/
    Car(){}
    ~Car(){}
    void CarON()
    {
        while(true)
        {
            cout << "CarOn" << endl;
            Eng.Consume(FueTan);
            FueTan.print();
            Sleep(1000);
            system("cls");
        }
    }
};

void main()
{
    setlocale(LC_ALL, "rus");
    Car Chepyrka;
    Chepyrka.CarON();
}

