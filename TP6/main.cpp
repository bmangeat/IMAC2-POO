// ------------------- //
// --- Exercice 2 --- //
//------------------ //

// #include <iostream>
// #include <string>
// #include <cmath>
// #include <exception>
//
// int main(int argc, char const *argv[])
// {
//   int a = 10;
//   int b = sqrt(0);
//   std::cout << "a/2 = " << a/2 << std::endl;
//   try {
//     if( b == 0 ){
//       throw std::domain_error("Oops une erreur s'est glissée.");
//     } else {
//       std::cout << "a/b = " << a/b << std::endl;
//     }
//   }
//   catch(const std::exception &e){
//    std::cerr << "Erreur : " << e.what() << std::endl;
//   }
//   catch(...){
//    std::cerr << "Oops i did it again";
//   }
//   std::cout << "a/5 = " << a/5 << std::endl;
//   std::cout << "Termine !! " << std::endl;
//   return 0;
// }


// ----------------------- //
// --- Exercice autre --- //
// --------------------- //

// #include <iostream>
// #include <future>
//
// int main(int argc, char const *argv[]) {
//   // future depuis un packaged_task
//    std::packaged_task<int()> task([](){ return 7; }); // wrap the function
//    std::future<int> f1 = task.get_future();  // get a future
//    std::thread(std::move(task)).detach(); // launch on a thread
//
//    // future depuis un async()
//    std::future<int> f2 = std::async(std::launch::async, [](){ return 8; });
//
//    // future depuis un promise
//    std::promise<int> p;
//    std::future<int> f3;
//
//    std::cout << "En attente...";
//    f1.wait();
//    f2.wait();
//
//    try{
//      if(!f3.get()){
//        throw std::future_error("f3 non défini");
//      }else{
//        f3.wait();
//      }
//    }
//
//    catch(const std::future_error &e){
//      std::cout << "Une erreur du futur est arrivée " << e.what() << std::endl;
//    }
//
//
//    std::cout << "Fait!\nLes resultats sont: "
//              << f1.get() << ' ' << f2.get() << ' ' << f3.get() << '\n';
//
//    return 0;
// }
