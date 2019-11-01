

import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as AwsAmplify from "aws-amplify";
import * as LogrTypes$ReasonMusicCtx from "./LogrTypes.bs.js";

function createLogger(name, level, param) {
  var tmp = { };
  if (name !== undefined) {
    tmp.name = Caml_option.valFromOption(name);
  }
  var tmp$1 = Belt_Option.map(level, LogrTypes$ReasonMusicCtx.levelToString);
  if (tmp$1 !== undefined) {
    tmp.level = Caml_option.valFromOption(tmp$1);
  }
  return new AwsAmplify.Logger(tmp);
}

function log(logger, level, message) {
  logger.log(LogrTypes$ReasonMusicCtx.levelToString(level), message);
  return /* () */0;
}

function logO(logger, level, message) {
  logger.log(LogrTypes$ReasonMusicCtx.levelToString(level), message);
  return /* () */0;
}

var Types = 0;

export {
  Types ,
  createLogger ,
  log ,
  logO ,
  
}
/* aws-amplify Not a pure module */
