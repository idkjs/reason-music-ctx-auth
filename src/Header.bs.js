

import * as React from "react";
import * as UserMenu$ReasonMusicCtx from "./UserMenu.bs.js";

function Header(Props) {
  return React.createElement("header", undefined, React.createElement("div", {
                  className: "user-menu"
                }, React.createElement(UserMenu$ReasonMusicCtx.make, { })));
}

var make = Header;

export {
  make ,
  
}
/* react Not a pure module */
