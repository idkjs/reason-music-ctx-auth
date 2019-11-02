/* ## Amplify Logger

Per the docs, for `Amplify Logger` to show message you have to the `window.Log_Level` to debug.

We do this one of two ways. The hacky, (read, have not figured out this part of reasonml, yet way) is:

```reason
let _ = [%bs.raw {|window.LOG_LEVEL = "DEBUG"|}];
```

The legit `reasonml` way, thanks to [@fham_r](https://mobile.twitter.com/fham_r) on [discord](https://discordapp.com/channels/235176658175262720/235176658175262720/639141028607164417), is:

```reason
type window;

[@bs.val] external window: window = "window";

[@bs.val] [@bs.scope "window"] external loglevel: string = "LOG_LEVEL";
[@bs.set] external setLogLevel: (window, string) => unit = "LOG_LEVEL";
/* this returns the value of `loglevel`! Did not know this syntax */
let loglevel = () => loglevel;
let setLogLevel = setLogLevel(window,"DEBUG");
``` */
type t;
type level =
  | Error
  | Warn
  | Info
  | Debug;
let levelToString =
  fun
  | Error => "ERROR"
  | Warn => "WARN"
  | Info => "INFO"
  | Debug => "DEBUG";

type options;
[@bs.obj]
external options: (~name: string=?, ~level: string=?, unit) => options = "";

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
[@bs.send] external debug: (t, string) => unit = "debug";
[@bs.send] external debugO: (t, Js.t({..})) => unit = "debug";

[@bs.send] external log: (t, string, string) => unit = "log";
[@bs.send] external logO: (t, string, Js.t({..})) => unit = "log";
[@bs.send] external logO: (t, string, string) => unit = "log";
let log = (logger, level, message) =>
  log(logger, levelToString(level), message);
let logO = (logger, level, message) =>
  logO(logger, levelToString(level), message);