using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SoundManager : MonoBehaviour
{
    public AudioClip enemyExplosion;

    public static SoundManager Instance = null;
    private AudioSource soundEffectAudio;

    // Start is called before the first frame update
    void Start()
    {
        //ensures there is always 1 copy of this object
        //If there is another soundManager, it will destroy itself
        if (Instance == null)
        {
            Instance = this;
        }
        else if (Instance != this)
        {
            Destroy(gameObject);
        }

        //used to return the correct audio file
        AudioSource[] sources = GetComponents<AudioSource>();
        foreach (AudioSource source in sources)
        {
            if (source.clip == null)
            {
                soundEffectAudio = source;
            }
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void PlayOneShot(AudioClip clip)
    {
        soundEffectAudio.PlayOneShot(clip);
    }
}
