type t;
[@bs.module "@aws-amplify/core"] external hub: t = "Hub";

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
  data: CognitoUser.userResponseDecoder,
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

[@bs.send] external _listen: (t, string, cb) => unit = "listen";

[@bs.send] external _remove: (t, string, cb) => unit = "remove";

let listen = (channel, callback) =>
  _listen(hub, channel->channelToString, callback);

let remove = (channel, callback) =>
  _remove(hub, channel->channelToString, callback);