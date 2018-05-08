#include "utilities.h"

struct Place
{
  const char * Name;
  const char * Subject;
};

const Place places[] PROGMEM =
{
  {"Library", "Librarian"},
  {"Store", "Cashier"},
  {"Museum", "Guard"},
  {"Art gallery", "Curator"},
  {"Embassy", "Secretary"},
  {"Newspaper", "Reporter"},
  {"Minimarket", "Shopper"},
  {"Bank", "Investor"},
  {"Currency exchange", "Cashier"},
  {"Travel agency", "Representative"},
  {"Municipality", "Secretary"},
};

const byte TOTAL_PLACES = ArrayLength(places);

const char noclue_1[] PROGMEM = "I haven't seen anybody with that description";
const char noclue_2[] PROGMEM = "No idea, sorry";
const char noclue_3[] PROGMEM = "No clue about that, sorry";
const char * noclue[] = {  noclue_1, noclue_2, noclue_3, };

struct Destination
{
  const char * Name;
  const char * Country;
  byte X;
  byte Y;
  // const char * Description;
  const char * Flag;
  const char * Language;
  const char * Currency;
  /*  const char * HintWanted;
    const char * HintLooking;
    const char * HintResearching;
    const char * HintReading;*/
};

const Destination destinations[] PROGMEM =
{
  {"Tokyo", "Japan", 97, 35, "white and red with a circle", "Japanese", "yens"},
  {"Vienna ", "Austria", 54, 14, "red and white with stripes", "German", "euros"},
  {"Barcelona", "Spain", 52, 17, "yellow and red with stripes", "Spanish", "euros"},
  {"Tromso", "Norway", 56, 7, "red, blue and white", "Bokmal", "krones"},
  {"Paris", "France", 52, 13, "red, blue and white with stripes", "French", "euros"},
  {"Sydney ", "Australia", 108, 49, "red, blue and white", "English", "dollars"},
  {"Rome", "Italy", 55, 17, "green , white and red with stripes", "Italian", "euros"},
  {"Munich", "Germany", 56, 13, "yellow, black and red with stripes", "German", "euros"},
  {"Budapest", "Hungary", 58, 15, "red, green and white with stripes", "Hungarian", "forints"},
  {"Amsterdam", "Netherlands", 54, 13, "red, white  and blue stripes", "Dutch", "euros"},
  {"Santiago", "Chile", 26, 51, "red, white and blue", "Spanish", "pesos"},
  {"Singapore", "Singapore", 93, 33, "red and white", "English", "dollars"},
  {"London", "England", 51, 10, "red, blue and white with crosses", "English", "pounds"},
  {"Istanbul", "Turkey", 64, 20, "red and white", "Turkish", "liras"},
  {"Cape Town", "South Africa", 58, 50, "colorful", "English", "rands"},
};
/*

  const Destination destinations[] = {
  {"Tokyo","Japan",97,35,"Capital of Japan and where the Emperor lives","white and red with a circle in the middle","Japanese","yens","experience the cherry blossoms","a robot toy","most populated city in the world","sashimi",},
  {"Vienna ","Austria",54,14,"Austria's capital and political, cultural and economic center","red and white with three horizontal stripes","German","euros","visit Sigmund Freud's home","Mozart balls","the City of Music","collection of Klimt's work",},
  {"Barcelona","Spain",52,17,"Second largest city of Spain","yellow and red with horizontal stripes","Spanish","euros","visit the capital of Catalonia","a traditional torero's suit","Gaudi's Sagrada Familia","tapas",},
  {"Tromso","Norway",56,7,"City of northern Norway above the Artic Circle","red, blue and white with a cross pattern","Bokmål","krones","experience the northern lights","reindeer meat","the midnight sun","cross country skiing",},
  {"Paris","France",52,13,"Capital of France and it´s most populated city","red, blue and white with vertical stripes","French","euros","climb the Eiffel Tower","baguette and crème brûlée","the city of love","Mona Lisa",},
  {"Sydney ","Australia",108,49,"Biggest and most populated city of Australia","red, blue and white with another flag inside","English","dollars","see an opera ","jumping kangaroos","surfing with sharks ","Koalas",},
  {"Rome","Italy",55,17,"Capital of Italy and place to 3,000 year old art and arquitecture","green , white and red with vertical stripes","Italian","euros","imagine gladiators ","pizza and spaguetti","Michelangelo's near touching hands","the Pope's house",},
  {"Munich","Germany",56,13,"City of Germany with supposed best cuality of life","yellow, black and red with horizontal stripes","German","euros","drink some good beer ","the largest science and tecnology museum ","eating white sausage for breackfast","the monks' place",},
  {"Budapest","Hungary",58,15,"Capital of Hungary where Danube river passes","red, green and white with horizontal stripes","Hungarian","forints","bathe in hot waters","Goulash","inventor of Kubik's cube","the country with highest rankings, per capita, for Nobel winners",},
  {"Amsterdam","Netherlands",54,13,"Capital of the Netherlands with an elaborate water channel system","red, white  and blue with horizontal stripes","Dutch","euros","smell tulips","places to ride a bicycle","Vincent van Gogh's country of origin","place where they have more than 10,000 operational windmills",},
  {"Santiago","Chile",26,51,"Capital of Chile and located in it's central valley","red, white  and blue with a star","Spanish","pesos","drink some good wine","places to eat good empanadas","air polution","Los Andes Mountains",},
  {"Singapore","Singapore",93,33,"Sovereign city-state and island country in Southeast Asia","red and white  with a half a moon and five stars","English","dollars","go to one of the most expensives cities","Marina Bay","prohibition of eating chewing gum","Hainanese chicken rice dishes",},
  {"London","England",51,10,"Capital and England's most polulated city","red, blue and white with combination of crosses","English","pounds","climb the eye","the Big Ben","places to eat fish and chips","Jack the ripper",},
  {"Istanbul","Turkey",64,20,"Historically known as Constantinople and Byzantium","red and white  with a semi cricle and star","Turkish","liras","visit the Sultanahmet Mosque","hand painted ceramic plates","one of the world's most famous empires","the Dolmabahce Palace",},
  {"Cape Town","South Africa",58,50,"Second-most populous urban area in South Africa after Johannesburg","green in the center and other colors with a Y shape ","English","rands","go to the Table Mountain","African wood carvings","populous african cities","Cape Point",},
  {"Mexico City","Mexico",14,27,"","green , red and white with a round shield in the middle","Spanish","pesos","","","","",},
  {"Bruges","Belgium",52,13,"","black, red and yellow with three vertical stripes","Flemish","euros","","","","",},
  {"Lucerne","Switzerland",54,14,"","red and white  with a cross in the middle","German","francs","","","","",},
  {"New York","USA",27,15,"","blue, red and white with lot's of stars","English","dollars","","","","",},
  {"Rio de Janeiro","Brazil",35,46,"","green, yellow and blue with a circle in a diamond","Portuguese","reais","","","","",},

*/


const byte TOTAL_DESTINATIONS = ArrayLength(destinations);

// TODO: Convert to bits!
const byte connections[TOTAL_DESTINATIONS * TOTAL_DESTINATIONS] PROGMEM = {
  0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0,
  1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0,
  0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
  0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0,
  0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0,
  0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0,
  1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0,
  0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1,
  0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0,
  0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0,
  0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0,
  0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0,
  0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0,
  0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0,
};

/*
  const bool connections[][20] PROGMEM  = {
  {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,},
  {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,},
  {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,},
  {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0,},
  {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1,},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,},
  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,},
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0,},
  {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0,},
  {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0,},
  {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0,},
  {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1,},
  {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,},
  {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,},
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,},
  {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,},
  {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,},
  {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1,},
  {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,},
  };*/

