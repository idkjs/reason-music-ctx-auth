/* https://github.com/aws-amplify/amplify-js/blob/master/packages/core/src/Hub.ts
   hub export `export default Hub;`
   node_modules/@aws-amplify/core/src/Hub.t */
type t;
[@bs.module "aws-amplify"] external hub: t = "Hub";
type event = [ | `signIn | `signUp | `signOut | `signIn_failure | `configured];
type channel = [
   | `core
   | `auth
   | `api
   | `analytics
   | `interactions
   | `pubsub
   | `storage
   | `xr
];
type hubPayload = {
  event,
  data: option(Js.Json.t),
  message: option(string),
};

type hubCapsule = {
  channel,
  payload: hubPayload,
  source: string,
  patternInfo: option(array(string)),
};
type hubCallback = {capsule: hubCapsule};
type cb = hubCallback => unit;
/*
 Define a function which calls Hub's `listen` function. It takes our `t` type hub a string for the name of the channel we want to listen to and a callback. Here is typed to the types in `Hub.ts` but it works with a simpler version as well(for future reference):
 ```
 [@bs.send]
 external listen: (t, string, Js.Json.t => unit) => unit = "listen";
 ```

 We also use `[@bs.string]` to limit the string input to channels defined in the js. We can add other channels. This list defines the protected channels in the source.
 */
[@bs.send]
external listen:
  (
    t,
    [@bs.string] [
      | `core
      | `auth
      | `api
      | `analytics
      | `interactions
      | `pubsub
      | `storage
      | `xr
    ],
    cb
  ) =>
  unit =
  "listen";

type listen;
 [@bs.send] external listen: (t, channel, cb) => unit = "listen";
 type remove;
 [@bs.send] external remove: (t, channel, cb) => unit = "remove";
 let listen = (string, callback) => listen(hub, string, callback);
let remove = (string, callback) => remove(hub, string, callback);
/* use currying to pass `hub` in here and `string` and `hubCallback` at the call site. */
// let listen = (channel, hubCallback) => listen(hub, channel, hubCallback);
// type hub;
// [@bs.module "@aws-amplify/core"] external hub: hub = "Hub";
// type logger;
// [@bs.new] [@bs.module "@aws-amplify/core"] external logger: logger = "Logger";
// [@bs.send] external info: unit => logger = "info";
// [@bs.send] external error: unit => logger = "error";

// // type logger;
// // [@bs.module "@aws-amplify/core"] [@bs.new]
// // external logger: (string, unit) => logger = "Logger";
// // [@bs.send] external error: (string) =>logger = "error";
// /*    | "signOut" => setUser(_ => None)

//       | "signIn_failure" => logger("user sign in failed") |> ignore

//       | "configured" */
// type event = [ | `signIn | `signUp | `signOut | `signIn_failure | `configured];
// type channel = [
//   | `core
//   | `auth
//   | `api
//   | `analytics
//   | `interactions
//   | `pubsub
//   | `storage
//   | `xr
// ];
// module HubPayload = {
//   [@bs.deriving abstract]
//   type t('a) = {
//     event: string,
//     data: Js.Nullable.t('a),
//     message: option(string),
//   };
//   let make = t;
// };
// // [@bs.deriving abstract]
// // type payloadJs = {
// //   event,
// //   data: Js.Nullable.t(Js.t({.})),
// //   [@bs.optional]
// //   message: string,
// // };
// type payloadJs = {
//   .
//   "event": event,
//   "data": Js.Nullable.t(Js.t({.})),
//   "message": string,
// };
// // type payload('a) = {
// //   event: string,
// //   data: Js.Nullable.t(Js.t('a)),
// //   message: option(string),
// // };
// type payload('a) = {
//   event,
//   data: option('a),
//   message: option(string),
// };

// type cb = payloadJs => unit;

// type listen;
// [@bs.send] external listen: (hub, channel, cb) => unit = "listen";
// type remove;
// [@bs.send] external remove: (hub, channel, cb) => unit = "remove";

// let listen = (string, callback) => listen(hub, string, callback);
// let remove = (string, callback) => remove(hub, string, callback);