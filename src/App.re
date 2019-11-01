type window;

[@bs.val] external window: window = "window";

[@bs.val] [@bs.scope "window"] external loglevel: string = "LOGLEVEL";
[@bs.set] external setLogLevel: (window, string) => unit = "LOGLEVEL";

let loglevel = () => loglevel;
let setLogLevel = setLogLevel(window);
open AuthTypes;
type state = {user};
let reducer = (_, action) =>
  switch (action) {
  | UserLoggedIn(authData) => {user: LoggedIn(authData)}
  | UserLoggedOut => {user: Anonymous}
  };

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, {user: Anonymous});
  let checkUser = () => {
    Js.Promise.(
      Auth.currentAuthenticatedUser
      // Auth.currentUserPoolUser(~userPoolId=Amplify.Config.userPoolId)
      |> then_(res => {
           let x = res->AuthTypes.fromJs;
           let userData: AuthTypes.userData = {
             isLoggedIn: true,
             username: Js.Nullable.return(x.username),
             id: Js.Nullable.return(x.attributes.sub),
             email: Js.Nullable.return(x.attributes.email),
           };
           //  let userInfo: AuthTypes.userInfo = {username: user##username, attributes: user##attributes};
           Js.log("sign up success!");
           Js.log(userData);
           dispatch(UserLoggedIn(userData));
           //  setUser(_ => Some(userInfo));
           //  let formTypeToUpdate: FormTypes.formType = SignUp;
           //  updateFormType(_ => SignUp);
           resolve();
         })
      |> catch(err => {
           Js.log(err);
           let errMsg = "error signing up.." ++ Js.String.make(err);
           Js.log(errMsg);
           resolve();
         })
      |> ignore
    );
  };
  open Logr;
  let logr = str => Js.log2(str);

  let logger = createLogger(~name="UserProvider", ~level=Info, ());
  open Hub;

  let listener: Hub.cb =
    data => {
      Js.log2("listener_data_appre", data);
      Logr.log(logger, Info, "listening for auth events...");
      // Logr.logO(logger, Info, payload);
      // Logr.info("listening for auth events...");
      let payload = data->payloadGet;
      Js.log2("payload", payload->eventGet);
      // let event = data.capsule.payload.event;
      let event = payload->eventGet;
      Js.log2("listener_data_event_appre", event);
      switch (event) {
      | "signIn" => logr("signIn_event", payload)
      // | `signUp => logger("user signed up") |> ignore

      | "signOut" =>
        logr("appre_logger_msg: user signed in", payload);
        dispatch(UserLoggedOut);

      // | `signIn_failure => logger("user sign in failed") |> ignore

      // | `configured => logger(payload) |> ignore
      | _ => Js.log2("logger", data) |> ignore
      };
    };
  React.useEffect1(
    () => {
      checkUser();
      // Hub.listen(`auth, listener);
      // Some(() => Hub.remove(`auth, listener));
      Hub.listen(Auth, listener);
      Some(() => Hub.remove(Auth, listener));
    },
    [||],
  );
  <UserContext.Provider value=(state.user, dispatch)>
    <Home />
  </UserContext.Provider>;
};