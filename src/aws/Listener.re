open Hub;
let logger = str => Js.log(str);
let useListerner = () => {
  let listener: Hub.cb =
    data => {
      Js.log2("listener_hubCallback", data);

      let event = data->payloadGet->eventGet->eventFromString;
      Js.log2("listener_hubCallback_event", event);
      switch (event) {
      | SignIn => logger("profile_logger_msg: user signed in")
      | SignUp => logger("profile_logger_msg: user signed up")

      | SignOut => logger("profile_logger_msg: user signed out")

      | SignIn_failure => logger("profile_logger_msg: user sign in failed")

      | Configured =>
        logger("profile_logger_msg: the Auth module is configured")
      | _ => logger("unknown error")
      };
    };
  React.useEffect1(
    () => {
      Auth.checkUser();
      Hub.listen(Auth, listener);
      Some(() => Hub.remove(Auth, listener));
    },
    [||],
  );
};