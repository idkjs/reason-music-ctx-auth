module Types = LogrTypes;
open Types;
type event = [ | `signIn | `signUp | `signOut | `signIn_failure | `configured];

type payloadJs = {
  .
  "event":event,
  "data": Js.Nullable.t(Js.t({.})),
  "message": string,
};
type t = logger;
type options;
[@bs.obj]
external options: (~name: string=?, ~level: string=?, unit) => options = "";
/*
 [@bs.module "winston"] external createLogger: options => t = "";
 let createLogger = (~level=?, ~format=?, ~defaultMeta=?, ~transports=?, ()) =>
   options(
     ~level=?Belt.Option.map(level, levelToString),
     ~format?,
     ~defaultMeta?,
     ~transports?,
     (),
   )
   |> createLogger; */

[@bs.module "aws-amplify"][@bs.new] external createLogger: options => t = "Logger";
let createLogger = (~name=?, ~level=?, ()) =>
  options(~name?, ~level=?Belt.Option.map(level, levelToString), ())
  |> createLogger;

[@bs.send] external error: (t, string) => unit = "error";
[@bs.send] external errorO: (t, Js.t({..})) => unit = "error";
[@bs.send] external warn: (t, string) => unit = "warn";
[@bs.send] external warnO: (t, Js.t({..})) => unit = "warn";
[@bs.send] external info: (t, string) => unit = "info";
[@bs.send] external infoO: (t, Js.t({..})) => unit = "info";
[@bs.send] external verbose: (t, string) => unit = "verbose";
[@bs.send] external verboseO: (t, Js.t({..})) => unit = "verbose";
[@bs.send] external debug: (t, string) => unit = "debug";
[@bs.send] external debugO: (t, Js.t({..})) => unit = "debug";

[@bs.send] external log: (t, string, string) => unit = "log";
[@bs.send] external logO: (t, string, Js.t({..})) => unit = "log";
[@bs.send] external logO: (t, string, payloadJs) => unit = "log";
let log = (logger, level, message) =>
  log(logger, levelToString(level), message);
let logO = (logger, level, message) =>
  logO(logger, levelToString(level), message);

// [@bs.send] external child: (t, Js.t({..})) => t = "";
// type loggerError = {
//   .
//   "code": string,
//   "name": string,
//   "message": string,
// };

// type logLevel = [ | `VERBOSE | `DEBUG | `INFO | `WARN | `ERROR];
// type cb = Js.Null.t(array(string)) => unit;

// type opts;
// [@bs.obj]
// external opts: (~name: string=?, ~level: logLevel=?, unit) => opts = "";
// /*  */
// type t;
// [@bs.module "@aws-amplify/core"] [@bs.new]
// external new_: (~opts: opts=?, unit) => t = "Logger";
// // [@bs.send] external info: unit => t = "info";
// [@bs.send] external error: unit => t = "error";
// type info;
// [@bs.send] external infocb: (t, string, cb) => unit = "info";
// [@bs.send] external info: (t, string) => unit = "info";
// let opts = opts(~name="name", ~level=`VERBOSE, ());
// let logger = (): t => new_(~opts, ());
// // type remove;
// // [@bs.send] external remove: (hub, channel, cb) => unit = "remove";
// let info = string => info(logger(), string) /* logger2##info("string") /* [@bs.send] external inf*/*/ /* let logger2 = makeLogger(~name="name", ~level=`VERBOSE, ())*/;

// // type wasm = {
// //   .
// //   "info": [@bs.meth] (string => unit),
// //   "error": [@bs.meth] (string => unit),
// // };
// // [@bs.module "aws-amplify"] [@bs.new]
// // external makeLogger: (~name: string, ~level: logLevel, unit) => wasm =
// //   "Logger";