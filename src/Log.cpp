Log::Log(std::string log_src){
    log.open(log_src);
    if (log.is_open()) 
        std::cout<<"\n\033[0;32mINFO :: "<<log_src<<" created\033[0m\n\n";
    else {
        std::cout<<"\n\033[1;31mINFO :: "<<log_src<<" isn't created\033[0m\n\n";
    }
}

void Log::writeLog(std::string Str){
    time_t seconds = time(NULL);
    tm* timenow = localtime(&seconds);
    log<<"On ";
    log<<asctime(timenow);
    log<<Str<<"\n\n------------------------------------------------------------"<<"\n\n";
}