const str =
  "nå blir det selvfølgelig den fantastike caesar koden med en økt bokstav du skal bruke. mye av denne teksten er unødvendig, det er bare for å gi deg nok tekst å jobbe med. i juletreet finner du neste nøtt.";
const str2 = "abcdefghijklmnopqrstuvwxyzæøå";
const arr2 = str.split("").map((val, idx) => {
  if (val === "æ") return (str.charCodeAt(idx) - 199).toString();
  if (val === "ø") return (str.charCodeAt(idx) - 216).toString();
  if (val === "å") return (str.charCodeAt(idx) - 196).toString();
  if (val === ".") return val;
  if (val !== " ") return (str.charCodeAt(idx) - 92).toString();
  else return "_";
});
console.log(arr2.join(" "));
