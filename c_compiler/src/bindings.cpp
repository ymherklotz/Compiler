#include "bindings.hpp"


// VariableStackBindings definition

VariableStackBindings::VariableStackBindings()
    : break_label_(""), continue_label_(""), stack_counter_(0), expression_stack_(16)
{}

void VariableStackBindings::insertBinding(const std::string &id, TypePtr type, const int &stack_position)
{
    auto binding = bindings_.find(id);

    if(binding == bindings_.end())
    {
	DeclarationData decl_data;
	decl_data.type = type;
	decl_data.stack_position = stack_position;
	bindings_.insert(std::pair<std::string, DeclarationData>(id, decl_data));
    }
    else
    {
	(*binding).second.stack_position = stack_position;
	(*binding).second.type = type;
    }
}

void VariableStackBindings::increaseStackPosition()
{
    stack_counter_ += 4;
}

void VariableStackBindings::increaseStackPosition(const int &position)
{
    stack_counter_ += position;
}

void VariableStackBindings::setStackPosition(const int &stack_counter)
{
    stack_counter_ = stack_counter;
}

void VariableStackBindings::nextExpressionStackPosition()
{
    expression_stack_ += 4;
}

void VariableStackBindings::setExpressionStackPosition(const int &stack_counter)
{
    expression_stack_ = stack_counter;
}

TypePtr VariableStackBindings::getType(const std::string &id) const
{
    auto binding = bindings_.find(id);
    return (*binding).second.type;
}

std::string VariableStackBindings::breakLabel()
{
    return break_label_;
}

std::string VariableStackBindings::breakLabel(const std::string &label)
{
    break_label_ = label;
    return break_label_;
}

std::string VariableStackBindings::continueLabel()
{
    return continue_label_;
}

std::string VariableStackBindings::continueLabel(const std::string &label)
{
    continue_label_ = label;
    return continue_label_;
}

int VariableStackBindings::currentStackPosition() const
{
    return stack_counter_;
}

int VariableStackBindings::stackPosition(const std::string &id) const
{
    auto binding = bindings_.find(id);

    if(binding != bindings_.end())
	return (*binding).second.stack_position;

    else return 0;
}

int VariableStackBindings::currentExpressionStackPosition() const
{
    return expression_stack_;
}

bool VariableStackBindings::bindingExists(const std::string &id) const
{
    auto binding = bindings_.find(id);

    if(binding == bindings_.end())
	return false;

    else
	return true;
}
