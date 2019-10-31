// open SharedTypes;
open ReactUtils;

[@react.component]
let make = () => {
  let (user, dispatch) = UserContext.useUser();
  let (userName, setUserName) = React.useState(() => "musicLover");

  switch (user) {
  | Anonymous =>
    <form
      className="user-form"
      onSubmit={e => {
        ReactEvent.Form.preventDefault(e);
        dispatch(UserLoggedIn(userName));
      }}>
      <div className="field">
        <label className="label"> "Username"->React.string </label>
        <div className="control has-icons-left has-icons-right">
          <input
            className="input is-success"
            type_="text"
            placeholder="User name"
            value=userName
            onChange={e => {
              let value = ReactEvent.Form.target(e)##value;
              setUserName(_ => value);
            }}
          />
          <span className="icon is-small is-left">
            <i className="fas fa-user" />
          </span>
          <span className="icon is-small is-right">
            <i className="fas fa-check" />
          </span>
        </div>
        <p className="help is-success">
          "This username is available"->React.string
        </p>
      </div>
      <div className="control">
        <button type_="submit" className="button is-link">
          {s("Log in")}
        </button>
      </div>
    </form>
  | LoggedIn(userName) =>
    <div className="user-form">
      <span className="logged-in">
        {s("Logged in as: ")}
        <b> {s(userName)} </b>
      </span>
      <div className="control">
        <button
          className="button is-link"
          onClick={_ => dispatch(UserLoggedOut)}>
          {s("Log Out")}
        </button>
        </div>
    </div>
  };
};