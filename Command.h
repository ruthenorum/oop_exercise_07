#ifndef OOP7_COMMAND_H
#define OOP7_COMMAND_H
#include "Document.h"

class ICommand {
public:
    virtual void unexecute() = 0;
protected:
    std::shared_ptr<Document> doc_;
};

class InsertCommand : public ICommand {
public:
    void unexecute() override;
    explicit InsertCommand(std::shared_ptr<Document>& doc);
};

class RemoveCommand : public ICommand {
public:
    RemoveCommand(std::shared_ptr<Figure>& newFigure, size_t newIndex, std::shared_ptr<Document>& doc);
    void unexecute() override;
private:
    std::shared_ptr<Figure> figure_;
    size_t index_;
};

#include "Command.cpp"
#endif //OOP7_COMMAND_H
