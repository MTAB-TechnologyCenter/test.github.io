using System;
using System.Collections.Generic;
using System.Net.Http;
using System.Text;
using Newtonsoft.Json;

class Program
{
    static void Main(string[] args)
    {
        // Set up authentication with Zoho API
        string authToken = "your_auth_token_here";
        HttpClient httpClient = new HttpClient();
        httpClient.DefaultRequestHeaders.Add("Authorization", "Bearer " + authToken);

        // Set up API endpoint for scheduling bulk emails
        string url = "https://mail.zoho.com/api/accounts/{bikram.sa07@mtabtechnology.com}/messages/bulk";

        // Set up parameters for scheduling
        Dictionary<string, object> messageParams = new Dictionary<string, object>();
        messageParams.Add("from_address", "bikram.sa07@mtabtechnology.com");
        messageParams.Add("subject", "Example Email");
        messageParams.Add("body", "This is an example email scheduled with C# and the Zoho API.");
        messageParams.Add("is_html_content", false);

        List<Dictionary<string, object>> contactsParams = new List<Dictionary<string, object>>();
        Dictionary<string, object> contact1Params = new Dictionary<string, object>();
        contact1Params.Add("email", "gbikram666@gmail.com");
        contactsParams.Add(contact1Params);

        Dictionary<string, object> contact2Params = new Dictionary<string, object>();
        contact2Params.Add("email", "contact.bikramghosh@gmail.com");
        contactsParams.Add(contact2Params);

        Dictionary<string, object> params = new Dictionary<string, object>();
        params.Add("message", messageParams);
        params.Add("contacts", contactsParams);
        params.Add("schedule_time", "2023-04-13T10:00:00+05:30");

        // Replace {ACCOUNT_ID} with your actual Zoho Mail account ID
        url = url.Replace("{bikram.sa07@mtabtechnology.com}", "bikram.sa07@mtabtechnology.com");

        // Send request to API to schedule bulk email
        HttpResponseMessage response = httpClient.PostAsync(url, new StringContent(JsonConvert.SerializeObject(params), Encoding.UTF8, "application/json")).Result;

        // Print response from API
        Console.WriteLine(response.Content.ReadAsStringAsync().Result);
    }
}
