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
type event =
  | SignIn
  | SignUp
  | SignOut
  | SignIn_failure
  | Configured
  | Unknown;

let eventFromString =
  fun
  | "signIn" => SignIn
  | "signUp" => SignUp
  | "signOut" => SignOut
  | "signIn_failure" => SignIn_failure
  | "configured" => Configured
  | _ => Unknown;
[@bs.deriving abstract]
type attributes = {
  sub: int,
  email_verified: bool,
  email: string,
  phone_number: string,
};
[@bs.deriving abstract]
type data = {
  username: string,
  [@bs.as "Session"]
  session: Js.Nullable.t(Js.t({.})),
  attributes,
};
[@bs.deriving abstract]
type payload = {
  event: string,
  data,
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