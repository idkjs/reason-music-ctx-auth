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
  open Logr;
  let logr = str => Js.log2(str);

  let logger = createLogger(~name="UserProvider", ~level=Info, ());
  open Hub;

  let listener =
    data => {
      Js.log2("listener_data_appre", data);
      Logr.log(logger, Info, "listening for auth events...");
      Logr.logO(logger, Info, data->payloadGet);
      Logr.info(logger, "listening for auth events...");
      let payload = data->payloadGet;
      Js.log2("appre_payload_appre", payload);
      let cognitoUserJs = payload->dataGet;
            Js.log2("appre_payloadData_appre", cognitoUserJs);

      let event = payload->eventGet;
      let cognitoUser = cognitoUserJs->CognitoUser.userResponsefromJs;
      Js.log2("appre_cognitoUser_appre", cognitoUser);
      Js.log2("appre_cognitoUser_appre", cognitoUser.username);

      Js.log2("appre_payload_event_appre", event);
      switch (event) {
      | "signIn" =>
        logr("appre_logr_signIn_event_data", data);
        let x = cognitoUser;
        let userData: AuthTypes.userData = {
          isLoggedIn: true,
          username: x.username,
          id: x.attributes.sub,
          email: x.attributes.email,
        };
        logr("userData signed up", userData);
        dispatch(UserLoggedIn(userData));
      | "signUp" => logr("user signed up", data)

      | "signOut" =>
        logr("appre_logger_msg: user signed in", payload);
        dispatch(UserLoggedOut);

      | "signIn_failure" => logr("user sign in failed", data)

      | "configured" =>
        logr("profile_msg: the Auth module is configured", data)
      | _ => logr("unknown error", data)
      };
    };
  React.useEffect1(
    () => {
      Hub.listen(Auth, listener);
      Some(() => Hub.remove(Auth, listener));
    },
    [||],
  );
  <UserContext.Provider value=(state.user, dispatch)>
    <Home />
  </UserContext.Provider>;
};