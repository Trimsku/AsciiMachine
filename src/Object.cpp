std::string Object::getName(){
    return Name;
}

Object::Object(std::string Name0){
    Name = Name0;
}
void Object::SetHitbox(int x1, int y1){
    x = x1;
    y = y1;
}

void Object::SetSprite(sf::Text name){
    sprites.push_back(name);
}