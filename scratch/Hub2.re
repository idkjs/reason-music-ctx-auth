type hub;
[@bs.module "@aws-amplify/core"] external hub: hub = "Hub";

// type logger;
// [@bs.module "@aws-amplify/core"] [@bs.new]
// external logger: (string, unit) => logger = "Logger";
// [@bs.send] external error: (string) =>logger = "error";
// [@bs.deriving abstract]
// type hubPayload = {
//   event:string,
//   data: option(Js.Json.t),
//   message: option(string),
// };

// [@bs.deriving abstract]
// type hubCapsule = {
//   channel:string,
//   payload: hubPayload,
//   source: string,
//   patternInfo: option(array(string)),
// };
// type hubCallback = {capsule: hubCapsule};
// [@bs.deriving abstract]
// type payloadJs = {
//   event: string,
//   data: Js.Nullable.t(Js.t({.})),
//   [@bs.optional]
//   message: string,
// };

// type payload = {
//   event: string,
//   data: Js.Nullable.t(Js.t({.})),
//   message: option(string),
// };
// [@bs.deriving abstract]
// type hubCallback = {capsule: hubCapsule};
// type cb = hubCallback => unit;
// type hubCapsule = {
//   channel: string,
//   payload,
//   source: string,
//   patternInfo: array(string),
// }
// and payload = {
//   event: string,
//   data: Js.Json.t,
//   message: string,
// };
// type cb = hubCapsule => unit;
[@bs.deriving abstract]
type payload = {
  event: string,
  data: Js.Json.t,
  message: string,
};
[@bs.deriving abstract]
type hubCapsule = {
  channel: string,
  payload,
  source: string,
  patternInfo: array(string),
};
external makeHubCapsuleResponse: 't => hubCapsule = "%identity";
type cbd = hubCapsule => unit;

type listen;
[@bs.send] external listen: (hub, string, cbd) => unit = "listen";
type remove;
[@bs.send] external remove: (hub, string, cbd) => unit = "remove";
// type listen;
// [@bs.send] external listen: (hub, string, cb) => unit = "listen";
// type remove;
// [@bs.send] external remove: (hub, string, cb) => unit = "remove";

let listen = (string, callback) => listen(hub, string, callback);
let remove = (string, callback) => remove(hub, string, callback);