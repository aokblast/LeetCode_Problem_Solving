//
//Runtime 39
//Memory Usage 41.9

/**
 * @param {string} date1
 * @param {string} date2
 * @return {number}
 */
var daysBetweenDates = function(date1, date2) {
    return Math.abs(((new Date(date2)) - (new Date(date1))) / 86400000);
};