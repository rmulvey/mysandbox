import java.math.*;
import java.text.*;
import java.time.*;
import java.time.format.*;
import java.util.*;

/**
 * Customers are billed based on their subscription tier for each user who was
 * active during a given day. You had a chat with some other engineers on the
 * team and decided that the following algorithm would work:
 * 
 * Requirements: 1. Calculate a daily rate for the active subscription tier 2.
 * For each day of the month, identify which users were active that day 3.
 * Multiply the number of active users for the day by the daily rate 4. Return
 * the running total at the end (because we're calculating money, round the
 * final amount back to 2 decimal places)
 * 
 * 
 * Note: Here is a link to a document I created that has the exact "assignment"
 * that caused this to be created:
 * https://docs.google.com/document/d/1XTmqs6AwmKXB_gY292ppfg1d5uD6zjxmOYf0H2q0vDc/edit
 */
class Subscription {
	public int id;
	public int customerId;
	public LocalDate startedOn;
	public LocalDate endedOn;
	public int monthlyPriceInDollars;

	/**
	 * Do not allow a no-arg constructor at this time. If future work can define
	 * proper default values that allow no-arg constructor that makes sense this may
	 * be added back
	 */
	private Subscription() {
	}

	public Subscription(int id, int customerId, LocalDate startedOn, LocalDate endedOn, int monthlyPriceInDollars) {
		this.id = id;
		this.customerId = customerId;
		this.startedOn = startedOn;
		this.endedOn = endedOn;
		this.monthlyPriceInDollars = monthlyPriceInDollars;
	}

}

/**
 * 
 * This class defines the attributes for a subscribed user.
 * 
 * @see Subscription
 */
class User {
	public int id;
	public String name;
	public LocalDate activatedOn;
	public LocalDate deactivatedOn;
	public int customerId;

	/**
	 * Do not allow a no-arg constructor at this time. If future work can define
	 * proper default values that allow no-arg constructor that makes sense this may
	 * be added back
	 */
	private User() {
	}

	public User(int id, String name, LocalDate activatedOn, LocalDate deactivatedOn, int customerId) {
		// TODO: Add some argument validation
		this.id = id;
		this.name = name;
		this.activatedOn = activatedOn;
		this.deactivatedOn = deactivatedOn;
		this.customerId = customerId;
	}

}

class Challenge {
	/**
	 * Calculate the total monthly bill using the algorithm described in the
	 * Subscription class description. Store intermediate results as any kind of
	 * decimal type (e.g. float, double). (Will not need to about rounding until the
	 * last step.)
	 * 
	 * @see Subscription
	 * 
	 * @param month - Will always be a valid YYYY-MM combination,
	 *  e.g. 2019-01 for January 2019. You will not need to handle any errors around this.
	 *  
	 * @param activeSubscription - Will contain the key monthly_price_in_dollars. May be null. 
	 * If present, the active_subscription will be active for the entire month, so you do 
	 * not need to worry about a subscription ending mid-month.
	 * 
	 * @param users - Contains user information as an array. May be empty, but not null. 
	 * Users may become active or inactive over the course of a month, as indicated by the 
	 * activated_on and deactivated_on date properties.
	 * 
	 * @return This method should return the total monthly bill for the customer, rounded 
	 * to 2 decimal places. 
	 */
	public static double billFor(String month, Subscription activeSubscription, User[] users) {
		// TODO: Add some argument validation
		// TODO: Review the parameter values and update code as needed
		double montlyTotal = 0.0;

		for (int i = 0; i < users.length; i++) {
			User thisUser = users[i];

			// Calculate a daily rate for the active subscription tier
			// Create a calendar object and set year and month
			Calendar mycal = new GregorianCalendar(activeSubscription.startedOn.getYear(),
					activeSubscription.startedOn.getMonthValue(), activeSubscription.startedOn.getDayOfMonth());
			// Get the number of days in that month
			int daysInMonth = mycal.getActualMaximum(Calendar.DAY_OF_MONTH);
			double dailyRate = activeSubscription.monthlyPriceInDollars / daysInMonth;

			// Note that a requirement was: "For each day of the month, identify which users
			// were active that day".
			// The code below does this in addition to determining how many days "this user"
			// was active for the
			// given month.
			// TODO: update this for this user's subscription.
			int activeDaysInMonth = daysInMonth;

			// Update daily rate for this specific used based on their actual subscription
			// dates. Note, this
			// may be 0 for this user.
			double thisUsersCharges = dailyRate * activeDaysInMonth;

			// Requirements asked to "Multiply the number of active users for the day by the
			// daily rate"
			// This loop replaces of the active used in the pass-in array with addition for
			// the same effect.
			montlyTotal += thisUsersCharges;

		}

		// Return the running total at the end (because we're calculating money,
		// round the final amount back to 2 decimal places)
		// TODO: This is not right... Fix it to actually round and not truncate
		DecimalFormat decFormat = new DecimalFormat("######.##");
		montlyTotal = Double.valueOf(decFormat.format(montlyTotal));
		return montlyTotal;
	}

	/*******************
	 * Helper functions *
	 *******************/

	private static LocalDate firstDayOfMonth(LocalDate date) {
		return date.withDayOfMonth(1);
	}

	private static LocalDate lastDayOfMonth(LocalDate date) {
		return date.withDayOfMonth(date.lengthOfMonth());
	}

	private static LocalDate nextDay(LocalDate date) {
		return date.plusDays(1);
	}
}