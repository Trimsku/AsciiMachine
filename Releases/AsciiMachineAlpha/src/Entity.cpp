Entity::Entity(std::string Name0)
    :BaseGUI(Name0)
{
    Name = Name0;
    logs.writeLog(getName() + "(type: Entity) is created");
}

Entity::~Entity()
{
    logs.writeLog(getName() + "(type: Entity) is destroyed");
}
void Entity::MinusHP(float minHP){
    hp -= minHP;
}
void Entity::PlusHP(float plusHP){
    hp += plusHP;
}

// Setters

void Entity::setAttack(float attack){
    Attack = attack;
}
void Entity::setHP(float HP){
    hp = HP;
}

// Getters

float Entity::getHP(){
    return hp;
}

std::string Entity::getName(){
    return Name;
}

float Entity::getAttack(){
    return Attack;
}