/* https://github.com/aws-amplify/amplify-js/blob/c4fdc5ce1d754c7d690a92336f81f108db0f0b51/packages/core/src/Logger/logger-interface.ts */
// type msg = string;
// type logger = {
// 	debug:(msg => unit),
// 	info:(msg => unit),
// 	warn:(msg => unit),
// 	error:(msg => unit),
// };
type logger;
type transport;
type format;

type level =
  | Error
  | Warn
  | Info
  | Verbose
  | Debug
  | Silly;
let levelToString =
  fun
  | Error => "ERROR"
  | Warn => "WARN"
  | Info => "INFO"
  | Verbose => "VERBOSE"
  | Debug => "DEBUG"
  | Silly => "SILLY";

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