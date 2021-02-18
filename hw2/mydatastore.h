

#include "datastore.h" 
#include "util.h"
#include <iostream> 
#include <map>
#include <cstdlib>
#include <string>

using namespace std;

class MyDataStore : public DataStore {
public: 
	MyDataStore();
	~MyDataStore();
	// ~DataStore(); /* *************** */

	/* search */
	vector<Product*> 			   search(std::vector<std::string>& terms, int type);

	/* Product functions*/
	void 						   addProduct(Product* p);

	/* Cart functions */
	map<string, vector<Product*> > addToCart  ();
	map<string, vector<Product*> > removeFromCart  ();
	map<string, vector<Product*> > buyCart  ();

	/* User functions */
	map<string, vector<User*> >    delUsers ();
	void 						   addUser(User* u);

	/* Display */
	void dump(std::ostream& ofile);
	map<string, vector<Product*> > displaySearch();
	map<string, vector<Product*> > displayAllProducts();
	
	map<string, vector<User*> >    displayUsers ();
	map<string, vector<Product*> > displayCart  ();


	/* Variables */
	map<string, vector<Product*> > products;
	map<string, vector<Product*> > cart;
	map<string, vector<User*> >    users;
	


};

/* searching, adding products and users, saving the database, etc. 
    //extra functions for the cart
    // map of string user to their cart (vector of products)
    // create a map of user names to the user
    // // pair(string, set<products>)
*/