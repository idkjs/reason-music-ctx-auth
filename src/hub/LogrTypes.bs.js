


function levelToString(param) {
  switch (param) {
    case /* Error */0 :
        return "ERROR";
    case /* Warn */1 :
        return "WARN";
    case /* Info */2 :
        return "INFO";
    case /* Verbose */3 :
        return "VERBOSE";
    case /* Debug */4 :
        return "DEBUG";
    case /* Silly */5 :
        return "SILLY";
    
  }
}

export {
  levelToString ,
  
}
/* No side effect */
