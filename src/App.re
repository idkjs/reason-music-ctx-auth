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
  open Logger;
  let logr = str => Js.log2(str);

  let logger = createLogger(~name="UserProvider", ~level=Info, ());
  open Hub;

  let listener =
    data => {
      Logger.log(logger, Info, "listening for auth events...");
      let message = data->payloadGet->messageGet;
      Logger.info(logger, "listening for auth events...");
      let userJs = data->payloadGet->dataGet;

      let event = data->payloadGet->eventGet->eventFromString;

      switch (event) {
      | SignIn =>
        Logger.logO(logger, Info, message);

        let userData: AuthTypes.userData = {
          isLoggedIn: true,
          username: userJs->usernameGet,
          id: userJs->attributesGet->subGet,
          email: userJs->attributesGet->emailGet,
        };
        dispatch(UserLoggedIn(userData));
      | SignUp => Logger.logO(logger, Info, message);

      | SignOut => Logger.logO(logger, Info, message);
        dispatch(UserLoggedOut);
      | SignIn_failure =>  Logger.logO(logger, Info, message);

      | Configured => Logger.logO(logger, Info, message);

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