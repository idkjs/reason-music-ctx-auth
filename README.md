# Reason Music Player with Auth Context Hook

## Mashup

This is a tutorial mashup [@sophiabrandt](https://github.com/sophiabrandt)'s [Reason Music Player](https://dev.to/sophiabrandt/how-to-create-a-music-player-in-reason-with-the-usecontext-hook-part-1-59dj) and
[@margaretkrutikova](https://github.com/MargaretKrutikova)'s [ReasonReact context explained in action](https://dev.to/margaretkrutikova/reason-react-context-explained-in-action-5eki) which you can read on [dev.to/t/reason](https://dev.to/t/reason)

Thanks to both of them for taking the time to share their knowledge. Blog post coming...

## Amplify Logger

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
```
