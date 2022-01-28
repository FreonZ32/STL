public interface ICar
{
    bool EngineIsRunning{ get; }

    void EngineStart();

    void EngineStop();

    void Refuel(double liters);

    void RunningIdle();
}

public interface IEngine
{
    bool IsRunning{ get; }

    void Consume(double liters);

    void Start();

    void Stop();
}

public interface IFuelTank
{
    double FillLevel{ get; }

    bool IsOnReserve{ get; }

    bool IsComplete{ get; }

    void Consume(double liters);

    void Refuel(double liters);
}

public interface IFuelTankDisplay
{
    double FillLevel{ get; }

    bool IsOnReserve{ get; }

    bool IsComplete{ get; }
}