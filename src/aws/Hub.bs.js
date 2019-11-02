

import * as Core from "@aws-amplify/core";

function channelToString(param) {
  switch (param) {
    case /* Core */0 :
        return "core";
    case /* Auth */1 :
        return "auth";
    case /* Api */2 :
        return "api";
    case /* Analytics */3 :
        return "analytics";
    case /* Interactions */4 :
        return "interactions";
    case /* Pubsub */5 :
        return "pubsub";
    case /* Storage */6 :
        return "storage";
    case /* Xr */7 :
        return "xr";
    
  }
}

function eventFromString(param) {
  switch (param) {
    case "configured" :
        return /* Configured */4;
    case "signIn" :
        return /* SignIn */0;
    case "signIn_failure" :
        return /* SignIn_failure */3;
    case "signOut" :
        return /* SignOut */2;
    case "signUp" :
        return /* SignUp */1;
    default:
      return /* Unknown */5;
  }
}

function listen(channel, callback) {
  Core.Hub.listen(channelToString(channel), callback);
  return /* () */0;
}

function remove(channel, callback) {
  Core.Hub.remove(channelToString(channel), callback);
  return /* () */0;
}

export {
  channelToString ,
  eventFromString ,
  listen ,
  remove ,
  
}
/* @aws-amplify/core Not a pure module */
