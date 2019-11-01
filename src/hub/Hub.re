type hub;
[@bs.module "@aws-amplify/core"] external hub: hub = "Hub";


type channel =
  | Core
  | Auth
  | Api
  | Analytics
  | Interactions
  | Pubsub
  | Storage
  | Xr;

let channelToString =
  fun
  | Core => "core"
  | Auth => "auth"
  | Api => "api"
  | Analytics => "analytics"
  | Interactions => "interactions"
  | Pubsub => "pubsub"
  | Storage => "storage"
  | Xr => "xr";

[@bs.deriving abstract]
type payload = {
  event: string,
  data: Js.Json.t,
  message: string,
};
[@bs.deriving abstract]
type hubCapsule = {
  channel,
  payload,
  source: string,
  patternInfo: array(string),
};
type cb = hubCapsule => unit;

type listen;
[@bs.send] external listen: (hub, string, cb) => unit = "listen";
type remove;
[@bs.send] external remove: (hub, string, cb) => unit = "remove";

let listen = (channel, callback) =>
  listen(hub, channel->channelToString, callback);
// let channel = channel->channelToString;

let remove = (channel, callback) =>
  remove(hub, channel->channelToString, callback);