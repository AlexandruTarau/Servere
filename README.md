# Alimentare Servere

 - Method: Divide et Impera
 - Complexity:
   - Time: ~O(nlogn)
      - Explanation: The for loop => O(n). The while loop's complexity increases slower and slower as n grows. Almost logarithmic (approximation).
   - Space: O(n)
      - Explanation: vector aux is declared with n elements.
 - We use an auxiliar vector to store the currents as we will need their initial values.
 - We calculate the average between the maximum and minimum current.
 - While the actual and previous currents are not closer than an error (0.01), we calculate the minimum power, store the current and update it by determining the average between it and the current with the minimum power.
 - If the old index and current index are the same, we continue to modify the value of the current. Else, when we switch to a new server (with the minimum power), we finally update the value of the current in the auxiliar vector and memorize the index (for future checks if the server changes again).
 - When the solution is within the error we print it.
