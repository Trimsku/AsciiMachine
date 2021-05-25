#include "../include/Color.hpp"

ascii::Palitra::Palitra(std::string palitra_name){
    PalitraName = palitra_name;
}

void ascii::Palitra::PushColor(std::string color_name, int r_, int g_, int b_, int a_ ){
    colornames.push_back(color_name);
    r.push_back(r_);
    g.push_back(g_);
    b.push_back(b_);
    a.push_back(a_);
}

std::string ascii::Palitra::getPalitraName() {
    return PalitraName;
}

void ascii::Palitra::printColors() {
    std::cout<<'\n';
    for(int i = 0; i < colornames.size(); i++){
        std::cout <<getPalitraName() << "::" << colornames[i] <<":\tr: " << r[i] << "\tg: "<< g[i] << "\tb: " << b[i] << "\ta: " << a[i] << "\n";
    }
    std::cout<<'\n';
}