

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
  listen ,
  remove ,
  
}
/* @aws-amplify/core Not a pure module */
