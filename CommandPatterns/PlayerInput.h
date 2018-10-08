
class FCommand
{
public:
    virtual ~FCommand() {}
    virtual void execute(AActor* Actor) = 0;
}

class FFireCommand : public FCommand
{
public:
    virtual void execute(AActor* Actor)
    {
        Actor->Fire();
    }
}

class FJumpCommand : public FCommand
{
public:
    virtual void execute(AActor* Actor)
    {
        Actor->Jump();
    }
}

class FInputHandle
{
public:
    FCommand* HandleInput()
    {
        if (IsPressed(ButtonX)) 
        {
            return ButtonX_;
        }

        if (IsPressed(ButtonY))
        {
            return ButtonY_;
        }

        return NULL;
    }
public:
    Command* ButtonX_;
    Command* ButtonY_;
}

int main(int argc, char** argv)
{
    InputHandle = new FInputHandle;
    InputHandle.ButtonX_ = new FFireCommand;
    InputHandle.ButtonY_ = new FJumpCommand;

    AActor* Actor = GetCurrentActor();

    FCommand* Command = InputHandle->HandleInput();
    if (command)
    {
        command->execute(Actor);
    }
}
