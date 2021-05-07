std::string BaseGUI::getName(){
    return Name;
}
BaseGUI::BaseGUI(std::string Name0){
    Name = Name0;
}

void BaseGUI::setHitbox( float x01, float y01, float x02, float y02){
    x0 = x01;
    y0 = y01;
    x1 = x02;
    y1 = y02;
}
float BaseGUI::getY0() {
    return y0; 
}
float BaseGUI::getX0() { 
    return x0; 
}
float BaseGUI::getY1() {
    return y1; 
}
float BaseGUI::getX1() { 
    return x1; 
}
