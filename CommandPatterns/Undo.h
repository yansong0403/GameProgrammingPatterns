
class FCommand
{
public:
    virtual ~Command() {}
    virtual void execute() = 0;
    virtual void undo() = 0;
}

class FMoveCommand : public FCommand
{
public:
    FMoveCommand(AActor* InActor, int32 X, int32 Y)
        : Actor(InActor), X_(X), Y_(Y), BeforeX_(0), BeforeY_(0) 
    {

    }
    virtual void Execute()
    {
        BeforeX_ = X_;
        BeforeY_ = Y_;
        Actor->MoveTo(X_, Y_);
    }
    virtual void Undo()
    {
        Actor->MoveTo(BeforeX_, BeforeY_);
    }
private:
    AActor* Actor;
    int32 X_, Y_;
    int32 BeforeX_, BeforeY_;
}

class Invoker
{
public:
    void RunCommand(FCommand* Command)
    {
       CmdList.push(Command);
       Command->Execute();
    }
    void UndoCommand()
    {
        CmdList.top()->Undo();
        CmdList.pop();
    }
private:
    stack<FCommand*> CmdList;
}
