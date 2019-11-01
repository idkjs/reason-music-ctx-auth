

import * as HubcallbackJson from "./hubcallback.json";

function decodePayload(data) {
  return /* record */[
          /* event */data.event,
          /* data */data.data,
          /* message */data.message
        ];
}

var res = HubcallbackJson.default;

function decode(data) {
  return /* record */[
          /* channel */data.channel,
          /* payload */decodePayload(res.payload),
          /* source */data.source,
          /* patternInfo */data.patternInfo
        ];
}

console.log("bc", res);

function hubcb(res) {
  return res;
}

console.log("bc", res);

var cb = res;

export {
  decodePayload ,
  res ,
  decode ,
  hubcb ,
  cb ,
  
}
/* res Not a pure module */
