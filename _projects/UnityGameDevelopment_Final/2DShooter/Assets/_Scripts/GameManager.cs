using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    public GameObject player;
    public GameObject[] spawnPoints;
    public GameObject enemy;
    public int score = 0;
    public PlayerController playerC;
    public SpriteRenderer playerSprite;

    public Text scoreText;
    //public Text livesText;
    //public Text restartText;
    //public Text gameOverText;

    //public int maxEnemiesOnScreen;
    //public int totalEnemies;
    public float minSpawnTime;
    public float maxSpawnTime;
    public int enemiesPerSpawn;

    private int enemiesOnScreen = 0;
    private float generatedSpawnTime;
    private float currentSpawnTime = 0;
    
    private int points = 100; //1 ship destroyed

    public void EnemyDestroyed()
    {
        //Debug.Log("dead ship");
        /*if (totalEnemies == 0)
        {
            Invoke("endGame", 2.0f);
        }*/
        AddScore(points);
        Debug.Log("current score: " + score);
    }

    public void AddScore(int newScoreValue)
    {
        score += newScoreValue;
        UpdateScore();
    }
    
    void UpdateScore()
    {
        scoreText.text = "Score: " + score;
    }



    // Start is called before the first frame update
    void Start()
    {

        score = 0;
        UpdateScore();
    }

    // Update is called once per frame
    void Update()
    {
        //prevents enemies from spawning after the player dissapears
        if (!playerSprite.enabled)
        {
            return;
        }

        //accumulates the amount of time that's passed between each frame update
        currentSpawnTime += Time.deltaTime;

        //code for spawning enemies
        if (currentSpawnTime > generatedSpawnTime)
        {
            //resets the spawn time
            currentSpawnTime = 0;
            //randomizes the spawn time
            generatedSpawnTime = Random.Range(minSpawnTime, maxSpawnTime);

            //logic that prevents from exceeding the max number of enemies
            //if (enemiesPerSpawn > 0 && enemiesOnScreen < totalEnemies)
            
            //continuously spawns enemies
            if (enemiesPerSpawn > 0)
            {
                List<int> previousSpawnLocations = new List<int>();

                //limits the number of enemies you can spawn by the number of spawn points
                if (enemiesPerSpawn > spawnPoints.Length)
                {
                    enemiesPerSpawn = spawnPoints.Length - 1;
                }

                //prevents the creation of enemies when the max number has been reached
                //enemiesPerSpawn = (enemiesPerSpawn > totalEnemies) ? enemiesPerSpawn - totalEnemies : enemiesPerSpawn;

                for (int i = 0; i < enemiesPerSpawn; i++)
                {
                    //if (enemiesOnScreen < maxEnemiesOnScreen)
                    if(true)
                    {
                        enemiesOnScreen += 1;
                        int spawnPoint = -1;
                        //runs until it finds a spawn point or the spawn point isn't -1
                        while (spawnPoint == -1)
                        {
                            //random number as a possible spawn point
                            int randomNumber = Random.Range(0, spawnPoints.Length - 1);

                            //checks if the number is already a spawn point, if it's empty then it sets the spawn point
                            if (!previousSpawnLocations.Contains(randomNumber))
                            {
                                previousSpawnLocations.Add(randomNumber);
                                spawnPoint = randomNumber;
                            }
                        }

                        //sets the spawn point based off the number we determined in the loops
                        GameObject spawnLocation = spawnPoints[spawnPoint];
                        GameObject newEnemy = Instantiate(enemy) as GameObject;

                        newEnemy.transform.position = spawnLocation.transform.position;
                        
                        Enemy enemyScript = newEnemy.GetComponent<Enemy>();
                        
                        /*enemyScript.target = player.transform;
                        Vector2 targetRotation = new
                            Vector2(player.transform.position.x,
                            newEnemy.transform.position.y);
                        newEnemy.transform.LookAt(targetRotation);*/

                        //whenever an alien is destroyed, the game manager gets notified
                        enemyScript.OnDestroy.AddListener(EnemyDestroyed);
                    }
                }
            }
        }

    }
}
