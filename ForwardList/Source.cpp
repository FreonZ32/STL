#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Car
{
    class Engine;
    class FuelTank;
    class FuelTankDisplay;

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

        void Consume(FuelTank& FueTan,Engine& Eng)
        {
            double fillLevel = FueTan.get_Fill_Level();
            fillLevel -= 0.0003;
            FueTan.set_FillLevel(fillLevel,Eng);
        }

        void RunningIdle();
    };
    class FuelTank
    { 
        double FillLevel;
        bool IsOnReserve;
        bool IsComplete;
        void Refuel(double liters);

    public:
        double get_Fill_Level()const
        {return FillLevel;}
        void set_FillLevel(double FillLevel, Engine& Eng)
        {
            if (FillLevel<=double(5)) { this->IsOnReserve = true; }
            else if (FillLevel == 0) { Eng.EngineStop(); this->IsComplete = true; }
            else this->FillLevel = FillLevel;
        }
        FuelTank(double FillLevel = 20,bool IsOnReserve = false,bool IsComplete = false)
        {
            this->FillLevel = FillLevel;
            this->IsOnReserve = IsOnReserve;
            this->IsComplete = IsComplete;
        }
        FuelTank(){}
        class FuelTankDisplay
        {
            double FillLevel;
            bool IsOnReserve;
            bool IsComplete;
        };
       // friend class Engine;
    };
    Engine Eng;
    FuelTank FueTan;
    FuelTank::FuelTankDisplay FueTanDis;
public:
    Engine get_Eng()const
    {return Eng;}
    FuelTank get_FueTan()const
    {return FueTan;}
    FuelTank::FuelTankDisplay get_FueTanDis()
    {return FueTanDis;}

    void CarON()
    {
        char C;
        C = getchar();
        while (C == 13)
        {

        }

    }
};

