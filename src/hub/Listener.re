open Hub;
let logger = str => Js.log(str);
let useListerner = () => {
  let listener: Hub.cb =
    data => {
      Js.log2("listener_hubCallback", data);

      let payload = data->payloadGet;
      Js.log2("payload", payload->eventGet);

      let event = payload->eventGet;
      Js.log2("listener_hubCallback_event", event);
      switch (event) {
      | "signIn" => logger("profile_logger_msg: user signed in")
      | "signUp" => logger("profile_logger_msg: user signed up")

      | "signOut" => logger("profile_logger_msg: user signed out")

      | "signIn_failure" => logger("profile_logger_msg: user sign in failed")

      | "configured" =>
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