std::string Entity::getName(){
    return Name;
}
Entity::Entity(std::string Name0)
    :Object(Name0)
{
    Name = Name0;
    logs.WriteLog(getName() + "(type: Entity) is created");
}

Entity::~Entity()
{
    logs.WriteLog(getName() + "(type: Entity) is destroyed");
}

