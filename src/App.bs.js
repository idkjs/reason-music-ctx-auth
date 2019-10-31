

import * as React from "react";

function App(Props) {
  return React.createElement("div", {
              className: "section is-fullheignt"
            }, React.createElement("div", {
                  className: "container"
                }, React.createElement("div", {
                      className: "column is-6 is-offset-4"
                    }, React.createElement("h1", {
                          className: "is-size-2 has-text-centered"
                        }, "Reason Music Player"), React.createElement("br", undefined))));
}

var make = App;

export {
  make ,
  
}
/* react Not a pure module */
