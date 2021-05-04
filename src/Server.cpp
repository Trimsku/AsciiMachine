void Server::SendStatus(Object *obj){
    OObject.push_back(obj);
}
Server::Server(){
    logs.WriteLog("Server class is created");
}
Server::~Server(){
    logs.WriteLog("Server class is destroyed");
}