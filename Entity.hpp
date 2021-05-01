
class Entity{
    private:
        int id;
        sf::Text text;
        std::string Name;
    Entity(int id0, std::string Name0, sf::Text texture){
        id = id0;
        Name = Name0;
        text = texture;
    }
    public:
    bool isFriendly;
    int Move;
    std::string getName(){
        return Name;
    }
    int getID(){
        return id;
    }


}


