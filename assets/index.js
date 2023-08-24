const arabicToRomanMap = [
  [1000, "M"],
  [900, "CM"],
  [500, "D"],
  [400, "CD"],
  [100, "C"],
  [90, "XC"],
  [50, "L"],
  [40, "XL"],
  [10, "X"],
  [9, "IX"],
  [5, "V"],
  [4, "IV"],
  [1, "I"],
];

const romanToArabicMap = new Map([
  ["I", 1],
  ["V", 5],
  ["X", 10],
  ["L", 50],
  ["C", 100],
  ["D", 500],
  ["M", 1000],
]);

const arabicInput = document.getElementById("arabicInput");
const romanInput = document.getElementById("romanInput");

arabicInput.addEventListener("input", () => {
  const arabicValue = parseInt(arabicInput.value);
  if (!isNaN(arabicValue)) {
    const romanValue = arabicToRoman(arabicValue);
    romanInput.value = romanValue;
  }
});

romanInput.addEventListener("input", () => {
  const romanValue = romanInput.value;
  const arabicValue = romanToArabic(romanValue);
  if (!isNaN(arabicValue)) {
    arabicInput.value = arabicValue;
  }
});

function arabicToRoman(arabic) {
  let result = "";
  for (const [value, symbol] of arabicToRomanMap) {
    while (arabic >= value) {
      result += symbol;
      arabic -= value;
    }
  }
  return result;
}

function romanToArabic(roman) {
  let result = 0;
  for (let i = 0; i < roman.length; i++) {
    const current = romanToArabicMap.get(roman[i]);
    const next = romanToArabicMap.get(roman[i + 1]);
    if (next && current < next) {
      result += next - current;
      i++;
    } else {
      result += current;
    }
  }
  return result;
}
